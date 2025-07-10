//***************************************************************************************
//                                        Modules
//***************************************************************************************
#pragma once
#include "CommDevices.h"

//***************************************************************************************
// Máscaras de comandos
//***************************************************************************************
#define BROAD_COMMAND            0xC0
#define ENDPOINT_COMMAND         0x80
#define ROUTER_COMMAND           0x40
#define COMMAND_SOURCE_MODULE    0x20
#define COMMAND_SOURCE_SOFTWARE  0x10
#define COMMAND_SOURCE_ROUTER    0x00
#define COMMAND_MASK             0x0F
#define SOURCE_MASK              0x30

//***************************************************************************************
// Definição de comandos utilizados pelos módulos
//***************************************************************************************
#define CMD_MESSAGE              0x00
#define CMD_GET_DATETIME         0x01
#define CMD_SET_DATETIME         0x02
#define CMD_SEND_SAMPLES         0x03
#define CMD_GET_CONTROL_CONFIG   0x04
#define CMD_SET_CONTROL_CONFIG   0x05
#define CMD_SAVE_CONFIG          0x06
#define CMD_POWER_DOWN           0x07
#define CMD_REQUEST_ACTION       0x08
#define CMD_SET_TIMEOUT          0x09
#define CMD_SET_SEND_TO_SERVER   0x0A

//***************************************************************************************
// // Frequências de alarme disponíveis
//***************************************************************************************
#define ALARM_EVERY_10_SECONDS      2
#define ALARM_EVERY_MINUTE          3
#define ALARM_EVERY_10_MINUTES      4
#define ALARM_EVERY_HOUR            5
#define ALARM_ONCE_A_DAY            6

//***************************************************************************************
// Classes
//***************************************************************************************
namespace Modules
{
	using namespace System;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Threading;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Text;
	using namespace CommDevices;

	//***********************************************************************************
	// Delegates
	//***********************************************************************************
	public delegate void ModuleReception(Object ^, array<unsigned char>^);
	public delegate void ModuleDisconnection(Object ^);

	//***********************************************************************************
	// Objects
	//***********************************************************************************
	public ref class Module
	{
		protected:
			Thread^ ReceptionThread;
			int rcvPos, rcvLimit;
			unsigned char chkSum;
			array<Byte>^ receptionBuffer, ^lastReceptionBuffer;
			int dataPos = 0;
			int state = 0;

		public:
			CommLayer ^Comm;
			ModuleReception ^onReceive;
			ModuleDisconnection ^onDisconnection;

			//===========================================================================
			// Construtores
			//===========================================================================
			Module() { Comm = nullptr; rcvPos = 0; state = 0; };
			Module(CommLayer ^c) { Comm = c; rcvPos = 0; state = 0; };

			//===========================================================================
			// Propriedades
			//===========================================================================
			property bool Connected
			{
				bool get()
				{
					if (Object::ReferenceEquals(Comm, nullptr) == false)
						return(Comm->Connected);
					else
						return(false);
				}
				void set(bool state)
				{
					if (Object::ReferenceEquals(Comm, nullptr) == false)
						Comm->Connected = state;
				}
			}
			// Retorna a quantidade de dados no buffer de recepção
			property int BytesToRead
			{
				virtual int get(void)
				{
					int bytes;
					try
					{
						bytes = Comm->BytesToRead;
					}
					catch (System::IO::IOException ^)
					{
						onDisconnection(this);
					}
					return(bytes);
				}
			}

			//===========================================================================
			// Métodos
			//===========================================================================
			void Open(void)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
				{
					Comm->Open();
					if (Comm->Connected)
					{
						this->ReceptionThread = gcnew Thread(gcnew ThreadStart(this, &Module::ReceptionService));
						this->ReceptionThread->Start();
					}
				}
			}
			void Close(void)
			{
				try
				{
					if(Comm != nullptr)
					{
						Comm->Close();
						this->ReceptionThread->Abort();
					}
				}
				catch (NullReferenceException ^) {}
			}

			// Escreve um array de caracteres no buffer de transmissão
			void Write(array<unsigned char>^ buffer, int offset, int size)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
					Comm->Write(buffer, offset, size);
			}

			// Lê dados presentes no buffer de recepção
			int Read(array<unsigned char>^ buffer, int offset, int size)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
					return (Comm->Read(buffer, offset, size));
				else
					return (0);
			}
			void Clear(void)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
				{
					Comm->Clear();
				}
			}

			// Função de CRC8 utilizada para o protocolo de comunicação
			unsigned char crc8_update(unsigned char crc, unsigned char data)
			{
				crc ^= data;
				for (int i = 0; i < 8; ++i)
				{
					if ((crc & 0x80) != 0)
						crc = (unsigned char)((crc << 1) ^ 0x07);
					else
						crc <<= 1;
				}
				return crc;
			}

			void SendPacket(unsigned char cmd, array<unsigned char>^ buffer)
			{
				if (Object::ReferenceEquals(Comm, nullptr))
					return;

				unsigned char crc = 0x00;
				int totalSize = 4 + buffer->Length + 1; // cabeçalho (2) + tamanho (1) + comando (1) + payload + CRC (1)
				array<unsigned char>^ packet = gcnew array<unsigned char>(totalSize);

				// Header
				packet[0] = 0xAA;
				packet[1] = 0x55;
				packet[2] = (unsigned char)(buffer->Length + 2);
				packet[3] = cmd;

				// Payload
				Array::Copy(buffer, 0, packet, 4, buffer->Length);

				// Calcula o CRC8 sobre [0..totalSize - 2]
				for (int i = 2; i < totalSize - 1; ++i)
					crc = crc8_update(crc, packet[i]);

				// Adiciona o CRC no final
				packet[totalSize - 1] = crc;

				Comm->Write(packet, 0, packet->Length);
			}

			void SendPacket(unsigned char cmd)
			{
				if (Object::ReferenceEquals(Comm, nullptr))
					return;

				unsigned char crc = 0x00;
				int totalSize = 4 + 1; // cabeçalho (2) + tamanho (1) + comando (1) + CRC (1)
				array<unsigned char>^ packet = gcnew array<unsigned char>(totalSize);

				// Header
				packet[0] = 0xAA;
				packet[1] = 0x55;
				packet[2] = 2;
				packet[3] = cmd;

				// Calcula o CRC8 sobre [0..totalSize - 2]
				for (int i = 2; i < totalSize - 1; ++i)
					crc = crc8_update(crc, packet[i]);

				// Adiciona o CRC no final
				packet[totalSize - 1] = crc;

				Comm->Write(packet, 0, packet->Length);
			}

			// Rotina de tratamento de recepção
			void ReceptionService(void)
			{
				int readedBytes;
				array<unsigned char>^ header = gcnew array<Byte>(3);

				while (Comm->Connected)
				{
					try
					{
						if (Comm->BytesToRead)
						{
							if (Comm->Read(header, 0, 1) && header[0] == 0xAA)
							{
								if (Comm->Read(header, 1, 1) && header[1] == 0x55)
								{
									if (!Comm->Read(header, 2, 1))
										continue; // erro na leitura do tamanho, tenta de novo

									int totalSize = header[2];        // O tamanho do pacote inclui o CRC.
									int payloadSize = totalSize - 1;  // Retirando o CRC.

									receptionBuffer = gcnew array<unsigned char>(totalSize);
									readedBytes = 0;

									while (readedBytes < totalSize)
									{
										int n = Comm->Read(receptionBuffer, readedBytes, receptionBuffer->Length - readedBytes);
										if (n <= 0)
											break;

										readedBytes += n;
									}

									if (readedBytes < totalSize)     // Pacote incompleto, descarta e continua
										continue;

									// Validação CRC
									unsigned char crc = 0x00;
									// Calcula CRC dos bytes: [tamanho (header[2]) + payload] (tudo exceto o CRC)
									crc = crc8_update(crc, header[2]);
									for (int i = 0; i < payloadSize; i++)
									{
										crc = crc8_update(crc, receptionBuffer[i]);
									}

									if (crc == receptionBuffer[payloadSize])
									{
										// Pacote válido, dispara evento com payload (sem CRC)
										array<unsigned char>^ payloadOnly = gcnew array<unsigned char>(payloadSize);
										Array::Copy(receptionBuffer, 0, payloadOnly, 0, payloadSize);
										onReceive(this, payloadOnly);
									}
								}
							}
						}
						else
						{
							Thread::Sleep(10);
						}
					}
					catch (System::IO::IOException ^)
					{
						onDisconnection(this);
						return;
					}
				}
			}
	};
}