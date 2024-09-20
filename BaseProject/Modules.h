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
			long long packetCounter = 0;

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
					//if (Object::ReferenceEquals(Comm, nullptr) == false)
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
									Comm->Read(header, 2, 1);
									receptionBuffer = gcnew array<Byte>(header[2]);
									readedBytes = 0;
									packetCounter++;

									while (readedBytes < header[2])
										readedBytes += Comm->Read(receptionBuffer, readedBytes, receptionBuffer->Length - readedBytes);

									onReceive(this, receptionBuffer);
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