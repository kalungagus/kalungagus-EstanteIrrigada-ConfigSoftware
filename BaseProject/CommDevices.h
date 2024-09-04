//**************************************************************************************************************************
//                                                      CommLayers
// Descrição: Arquivo para dispositivos de comunicação
//**************************************************************************************************************************
#pragma once
#include <Windows.h>
#include <setupapi.h>
#include <Dbt.h>
#include <cliext/list>
#include <cliext/vector>

//**************************************************************************************************************************
// DEFINES
//**************************************************************************************************************************
#define MY_DEVICE_ID      "VID_10C4&PID_EA60"
#define SOF               0x89

namespace CommDevices
{
	using namespace System;
	using namespace cliext;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Threading;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;	// Need this to support "unmanaged" code.

	//***********************************************************************************
	// Delegates
	//***********************************************************************************
	public delegate void receptionCallBack(array<unsigned char>^);

	//**********************************************************************************************************
	// Enums
	//**********************************************************************************************************
	public enum class CommLayerType { USB, TCPIP4 };

#pragma region DLL imports
	/*
	In order to use these unmanaged functions from within the managed .NET environment, we need
	to explicitly import the functions which we will be using from other .DLL file(s).  Simply
	including the appropriate header files is not enough.

	Note: In order to avoid potential name conflicts in the header files (which we still use),
	I have renamed the functions by adding "UM" (unmanaged) onto the end of them.  To find
	documentation for the functions in MSDN, search for the function name without the extra
	"UM" attached.
	Note2: In the header files (such as setupapi.h), normally the function names are
	remapped, depending upon if UNICODE is defined or not.  For example, two versions of the
	function SetupDiGetDeviceInterfaceDetail() exist.  One for UNICODE, and one for ANSI.
	If the wrong version of the function is called, things won't work correctly.  Therefore,
	in order to make sure the correct one gets called (based on your compiler settings, which
	may or may not define "UNICODE"), it is useful to explicity specify the CharSet when doing
	the DLL import.
	*/

#ifdef UNICODE
#define	Seeifdef	Unicode
#else
#define Seeifdef	Ansi
#endif

	[DllImport("hid.dll", CharSet = CharSet::Seeifdef, EntryPoint = "HidD_GetHidGuid")]
	extern "C" HDEVINFO  HidD_GetHidGuidUM(
		LPGUID HidGuid);

	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiOpenDevRegKey")]
	extern "C" HKEY SetupDiOpenDevRegKeyUM(
		HDEVINFO DeviceInfoSet,
		PSP_DEVINFO_DATA DeviceInfoData,
		DWORD Scope,
		DWORD HwProfile,
		DWORD KeyType,
		REGSAM samDesired);

	[DllImport("Advapi32.dll", CharSet = CharSet::Seeifdef, EntryPoint = "RegQueryValueEx")]
	extern "C" LONG WINAPI RegQueryValueExUM(
		HKEY hKey,
		LPCTSTR lpValueName,
		LPDWORD lpReserved,
		LPDWORD lpType,
		LPBYTE lpData,
		LPDWORD lpcbData);

	[DllImport("Advapi32.dll", CharSet = CharSet::Seeifdef, EntryPoint = "RegCloseKey")]
	extern "C" HDEVINFO  RegCloseKeyUM(
		HKEY hKey);

	//Returns a HDEVINFO type for a device information set (USB HID devices in
	//our case).  We will need the HDEVINFO as in input parameter for calling many of
	//the other SetupDixxx() functions.
	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiGetClassDevs")]
	extern "C" HDEVINFO  SetupDiGetClassDevsUM(
		LPGUID  ClassGuid,					//Input: Supply the class GUID here. 
		PCTSTR Enumerator,					//Input: Use NULL here, not important for our purposes
		HWND  hwndParent,					//Input: Use NULL here, not important for our purposes
		DWORD  Flags);						//Input: Flags describing what kind of filtering to use.

											//Gives us "PSP_DEVICE_INTERFACE_DATA" which contains the Interface specific GUID (different
											//from class GUID).  We need the interface GUID to get the device path.
	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiEnumDeviceInterfaces")]
	extern "C" WINSETUPAPI BOOL WINAPI  SetupDiEnumDeviceInterfacesUM(
		HDEVINFO  DeviceInfoSet,			//Input: Give it the HDEVINFO we got from SetupDiGetClassDevs()
		PSP_DEVINFO_DATA  DeviceInfoData,	//Input (optional)
		LPGUID  InterfaceClassGuid,			//Input 
		DWORD  MemberIndex,					//Input: "Index" of the device you are interested in getting the path for.
		PSP_DEVICE_INTERFACE_DATA  DeviceInterfaceData);//Output: This function fills in an "SP_DEVICE_INTERFACE_DATA" structure.

														//SetupDiDestroyDeviceInfoList() frees up memory by destroying a DeviceInfoList
	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiDestroyDeviceInfoList")]
	extern "C" WINSETUPAPI BOOL WINAPI  SetupDiDestroyDeviceInfoListUM(
		HDEVINFO  DeviceInfoSet);			//Input: Give it a handle to a device info list to deallocate from RAM.

											//SetupDiEnumDeviceInfo() fills in an "SP_DEVINFO_DATA" structure, which we need for SetupDiGetDeviceRegistryProperty()
	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiEnumDeviceInfo")]
	extern "C" WINSETUPAPI BOOL WINAPI  SetupDiEnumDeviceInfoUM(
		HDEVINFO  DeviceInfoSet,
		DWORD  MemberIndex,
		PSP_DEVINFO_DATA  DeviceInfoData);

	//SetupDiGetDeviceRegistryProperty() gives us the hardware ID, which we use to check to see if it has matching VID/PID
	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiGetDeviceRegistryProperty")]
	extern "C"	WINSETUPAPI BOOL WINAPI  SetupDiGetDeviceRegistryPropertyUM(
		HDEVINFO  DeviceInfoSet,
		PSP_DEVINFO_DATA  DeviceInfoData,
		DWORD  Property,
		PDWORD  PropertyRegDataType,
		PBYTE  PropertyBuffer,
		DWORD  PropertyBufferSize,
		PDWORD  RequiredSize);

	//SetupDiGetDeviceInterfaceDetail() gives us a device path, which is needed before CreateFile() can be used.
	[DllImport("setupapi.dll", CharSet = CharSet::Seeifdef, EntryPoint = "SetupDiGetDeviceInterfaceDetail")]
	extern "C" BOOL SetupDiGetDeviceInterfaceDetailUM(
		HDEVINFO DeviceInfoSet,										//Input: Wants HDEVINFO which can be obtained from SetupDiGetClassDevs()
		PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,				//Input: Pointer to an structure which defines the device interface.  
		PSP_DEVICE_INTERFACE_DETAIL_DATA DeviceInterfaceDetailData,	//Output: Pointer to a strucutre, which will contain the device path.
		DWORD DeviceInterfaceDetailDataSize,						//Input: Number of bytes to retrieve.
		PDWORD RequiredSize,										//Output (optional): Te number of bytes needed to hold the entire struct 
		PSP_DEVINFO_DATA DeviceInfoData);							//Output

	[DllImport("user32.dll", CharSet = CharSet::Seeifdef, EntryPoint = "RegisterDeviceNotification")]
	extern "C" HDEVNOTIFY WINAPI RegisterDeviceNotificationUM(
		HANDLE hRecipient,
		LPVOID NotificationFilter,
		DWORD Flags);
#pragma endregion

	//**********************************************************************************************************
	// Classe CommLayer: define uma interface de comunicação
	//**********************************************************************************************************
	public ref class CommLayer abstract
	{
		protected:
			CommLayerType commtype;
			bool connected;

			//==================================================================================================
			// Event handlers
			//==================================================================================================
		public:
			//==================================================================================================
			// Propriedades
			//==================================================================================================
			property int BytesToRead
			{
				virtual int get(void) abstract;
			}
			property bool CanRead
			{
				virtual bool get(void) abstract;
			}
			property bool CanWrite
			{
				virtual bool get(void) abstract;
			}
			property bool Connected
			{
				virtual bool get(void) abstract;
				virtual void set(bool) abstract;
			}
			property CommLayerType CommType
			{
				virtual CommLayerType get(void) { return commtype; };
			}
			property Stream ^BaseStream
			{
				virtual Stream ^get(void) abstract;
			}

			//==================================================================================================
			// Métodos
			//==================================================================================================
			virtual void Write(array<unsigned char>^ buffer, int offset, int size) abstract;
			virtual int Read(array<unsigned char>^ buffer, int offset, int size) abstract;
			virtual void Open(void) abstract;
			virtual void Close(void) abstract;
			virtual void Clear(void) abstract;
	};

	//**********************************************************************************************************
	// Classe USBDevice: Define um dispositivo de comunicações USB
	//**********************************************************************************************************
	public ref class USBDevice : CommLayer
	{
		private:
			SerialPort ^virtualSerial;
			String^ VirtualComm;
			long int baudRate = 115200;

		public:
			//==================================================================================================
			// Construtores
			//==================================================================================================
			USBDevice() { commtype = CommLayerType::USB; };
			USBDevice(String ^port) : VirtualComm(port) { commtype = CommLayerType::USB; };

			//==================================================================================================
			// Propriedades
			//==================================================================================================
			// Retorna a quantidade de dados no buffer de recepção
			property int BytesToRead
			{
				virtual int get(void) override
				{
					int bytes;
					try
					{
						bytes = virtualSerial->BytesToRead;
					}
					catch (System::IO::IOException ^)
					{
						throw;
					}
					return(bytes);
				}
			}
			// Retorna se há dados para leitura
			property bool CanRead
			{
				virtual bool get(void) override
				{
					return(virtualSerial->BytesToRead != 0);
				}
			}
			// Sempre pode escrever na USB
			property bool CanWrite
			{
				virtual bool get(void) override
				{
					return(true);
				}
			}
			// Propriedade Connected indica se uma conexão foi realizada ou inicializa e finaliza conexões.
			property bool Connected
			{
				virtual bool get(void) override
				{
					if (virtualSerial == nullptr)
						return(false);
					else
						return(virtualSerial->IsOpen);
				}
				virtual void set(bool state) override
				{
					if (state == true)
					{
						virtualSerial = gcnew SerialPort(VirtualComm, baudRate, Parity::None, 8, StopBits::One);
						try
						{
							virtualSerial->Open();
						}
						catch (...)
						{
							throw;
						}
					}
					else
					{
						if (virtualSerial != nullptr)
						{
							try
							{
								virtualSerial->Close();
								//onClose(this);
							}
							// Se esta excessão foi lançada, é por que a porta já está fechada.
							catch (System::IO::IOException^) {}
							virtualSerial = nullptr;
						}
					}
				}
			}

			// Propriedade que define a porta virtual que será utilizada.
			property String ^COM
			{
				String ^get(void)
				{
					return(VirtualComm);
				}
				void set(String ^port)
				{
					VirtualComm = port;
				}
			}

			// Propriedade que retorna a Stream utilizada pelo dispositivo
			property Stream ^BaseStream
			{
				virtual Stream ^get(void) override
				{
					return(virtualSerial->BaseStream);
				}
			}

			// Propriedade que define a porta virtual que será utilizada.
			property long int BaudRate
			{
				long int get(void)
				{
					return(baudRate);
				}
				void set(long int baud)
				{
					baudRate = baud;
				}
			}

			//==================================================================================================
			// Métodos
			//==================================================================================================
			// Retorna uma lista de portas COM virtuais que estão ligadas a um dispositivo de testes.
			static array<String ^>^ getUSBDevicesList(void)
			{
				array<unsigned char>^ buffer = gcnew array<unsigned char>(1);
				List<String ^>^commNames = gcnew List<String^>(0);
				HDEVINFO DeviceInfoTable = INVALID_HANDLE_VALUE;
				SP_DEVINFO_DATA DevInfoData;
				PBYTE PropertyValueBuffer;
				DWORD InterfaceIndex = 0;
				DWORD dwRegType;
				DWORD dwRegSize;
				DWORD dwType;
				HKEY hKey;
				String^ DeviceIDToFind = MY_DEVICE_ID;
				String^ CommPort;
				bool MatchFound = false;
				bool isThread = false;
				int iQuant = 0;

				DeviceInfoTable = SetupDiGetClassDevsUM(NULL, TEXT("USB"), NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
				InterfaceIndex = 0;
				// Procura nas interfaces disponíveis aquelas que possuam o mesmo ID utilizado por dispositivos de teste.
				while (InterfaceIndex < 100)
				{
					DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
					if (!SetupDiEnumDeviceInfoUM(DeviceInfoTable, InterfaceIndex, &DevInfoData))
						break;
					SetupDiGetDeviceRegistryPropertyUM(DeviceInfoTable, &DevInfoData, SPDRP_HARDWAREID, &dwRegType, NULL, 0, &dwRegSize);
					PropertyValueBuffer = (BYTE *)malloc(dwRegSize);
					if (PropertyValueBuffer == NULL)
						break;
					if (!SetupDiGetDeviceRegistryPropertyUM(DeviceInfoTable, &DevInfoData, SPDRP_HARDWAREID, &dwRegType, PropertyValueBuffer, dwRegSize, NULL))
						break;
					#ifdef UNICODE
					String^ DeviceIDFromRegistry = gcnew String((wchar_t *)PropertyValueBuffer);
					#else
					String^ DeviceIDFromRegistry = gcnew String((char *)PropertyValueBuffer);
					#endif
					free(PropertyValueBuffer);
					DeviceIDFromRegistry = DeviceIDFromRegistry->ToLowerInvariant();
					DeviceIDToFind = DeviceIDToFind->ToLowerInvariant();
					MatchFound = DeviceIDFromRegistry->Contains(DeviceIDToFind);
					// Um dispositivo foi encontrado.
					if (MatchFound == true)
					{
						hKey = SetupDiOpenDevRegKeyUM(DeviceInfoTable, &DevInfoData, DICS_FLAG_GLOBAL, 0, DIREG_DEV, KEY_READ);
						if (hKey != INVALID_HANDLE_VALUE)
						{
							PropertyValueBuffer = (BYTE *)malloc(MAX_PATH);
							if (PropertyValueBuffer == NULL)
								break;
							RegQueryValueExUM(hKey, TEXT("PortName"), NULL, &dwType, PropertyValueBuffer, &dwRegSize);
							RegCloseKeyUM(hKey);
							#ifdef UNICODE
							CommPort = gcnew String((wchar_t *)PropertyValueBuffer);
							#else
							CommPort = gcnew String((char *)PropertyValueBuffer);
							#endif
							// Adiciona a porta encontrada à lista de Portas
							commNames->Add(CommPort);
							free(PropertyValueBuffer);
						}
					}
					InterfaceIndex++;
				}
				SetupDiDestroyDeviceInfoListUM(DeviceInfoTable);
				return(commNames->ToArray());
			}

			// Escreve um array de caracteres no buffer de transmissão
			virtual void Write(array<unsigned char>^ buffer, int offset, int size) override
			{
				try
				{
					virtualSerial->Write(buffer, offset, size);
				}
				catch (IOException ^)
				{
					throw;
				}
			}

			// Lê dados presentes no buffer de recepção
			virtual int Read(array<unsigned char>^ buffer, int offset, int size) override
			{
				return(virtualSerial->Read(buffer, offset, size));
			}
			virtual void Open(void) override
			{
				virtualSerial = gcnew SerialPort(VirtualComm, 115200, Parity::None, 8, StopBits::One);

				try
				{
					virtualSerial->Open();
				}
				catch (...)
				{
					throw;
				}
			}
			virtual void Close(void) override
			{
				if (virtualSerial != nullptr)
				{
					try
					{
						virtualSerial->Close();
					}
					// Se esta excessão foi lançada, é por que a porta já está fechada.
					catch (System::IO::IOException^) {}
					virtualSerial = nullptr;
				}

			}
			virtual void Clear(void) override
			{
				if (virtualSerial != nullptr)
					virtualSerial->DiscardInBuffer();
			}
	};

	//**********************************************************************************************************
	// Classe TCPIP4Device: Define um dispositivo de comunicações TCP/IP 4.
	//**********************************************************************************************************
	public ref class TCPIP4Device : CommLayer
	{
		protected:
			String ^ipAddress;
			TcpClient ^tcpClient;
			int portNumber;

		public:
			//==================================================================================================
			// Construtores
			//==================================================================================================
			TCPIP4Device() { commtype = CommLayerType::TCPIP4; };
			TCPIP4Device(String^ ipAddress, int portNumber)
			{
				this->ipAddress = ipAddress;
				this->portNumber = portNumber;
				this->connected = false;
				commtype = CommLayerType::TCPIP4;
			}

			~TCPIP4Device()
			{
				this->ipAddress = nullptr;
			}

			//==================================================================================================
			// Operadores
			//==================================================================================================
			// Operador para comparações
			bool operator==(String^ ipAddress)
			{
				return(this->ipAddress == ipAddress);
			}
			bool operator==(TCPIP4Device^ seg)
			{
				if (this->ipAddress == seg->ipAddress)
				{
					return(portNumber == seg->portNumber);
				}
				else
					return(false);
			}
			// Operador para checar diferenças
			bool operator!=(String^ ipAddress)
			{
				return(this->ipAddress != ipAddress);
			}
			bool operator!=(TCPIP4Device^ seg)
			{
				if (this->ipAddress != seg->ipAddress)
				{
					return(true);
				}
				else
					return(portNumber != seg->portNumber);
			}

			//==================================================================================================
			// Propriedades
			//==================================================================================================
			// Retorna a quantidade de dados no buffer de recepção
			property int BytesToRead
			{
				virtual int get(void) override
				{
					if ((tcpClient != nullptr) && (connected == true))
					{
						if (tcpClient->GetStream()->CanRead)
							return(tcpClient->Available);
						else
							return(0);
					}
					return(0);
				}
			}
			// Retorna se há dados para leitura
			property bool CanRead
			{
				virtual bool get(void) override
				{
					return(tcpClient->GetStream()->CanRead);
				}
			}
			// Verifica se o buffer de escrita pode receber mais dados
			property bool CanWrite
			{
				virtual bool get(void) override
				{
					return(tcpClient->GetStream()->CanWrite);
				}
			}

			// Define o endereço IP ao qual deve-se conectar.
			property String^ IP
			{
				String^ get() { return this->ipAddress; }
				void set(String^ ip) { this->ipAddress = ip; }
			}

			// Define o Port Number para se conectar
			property int PortNumber
			{
				int get() { return this->portNumber; }
				void set(int portNumber) { this->portNumber = portNumber; }
			}

			// Propriedade Connected indica se uma conexão foi realizada ou inicializa e finaliza conexões.
			property bool Connected
			{
				virtual bool get(void) override
				{
					if (tcpClient != nullptr)
					{
						if (connected == true)
						{
							try
							{
								if (tcpClient->Client->Poll(0, SelectMode::SelectRead))
								{
									array<unsigned char>^ buffer = gcnew array<unsigned char>(1);
									if (tcpClient->Client->Receive(buffer, SocketFlags::Peek) == 0)
									{
										connected = false;
									}
								}
							}
							catch (System::NullReferenceException^)
							{
								connected = false;
							}
							catch (System::Net::Sockets::SocketException^)
							{
								connected = false;
							}
						}
					}
					else
						connected = false;
					return(connected);
				}
				virtual void set(bool state) override
				{
					if (state == true)
					{
						Open();
					}
					else
					{
						Close();
					}
				}
			}

			// Propriedade que retorna a Stream utilizada pelo dispositivo
			property Stream ^BaseStream
			{
				virtual Stream ^get(void) override
				{
					return(tcpClient->GetStream());
				}
			}
			//==================================================================================================
			// Métodos
			//==================================================================================================
			// Escreve um array de caracteres no buffer de transmissão
			virtual void Write(array<unsigned char>^ buffer, int offset, int size) override
			{
				if (connected)
					tcpClient->GetStream()->Write(buffer, offset, size);
			}

			// Lê dados presentes no buffer de recepção
			virtual int Read(array<unsigned char>^ buffer, int offset, int size) override
			{
				if (connected)
					return(tcpClient->GetStream()->Read(buffer, offset, size));
				else
					return(0);
			}
			virtual void Open(void) override
			{
				if (connected == false)
				{
					IAsyncResult^ ar;
					connected = true;

					tcpClient = gcnew TcpClient();
					try
					{
						ar = tcpClient->BeginConnect(this->ipAddress, portNumber, nullptr, nullptr);
					}
					catch (SocketException^)
					{
						connected = false;
						throw;
					}
					System::Threading::WaitHandle^ wh = ar->AsyncWaitHandle;
					try
					{
						if (!ar->AsyncWaitHandle->WaitOne(TimeSpan::FromSeconds(2), false))
						{
							tcpClient->Close();
							delete ar;
							connected = false;
							throw gcnew SocketException(WSAECONNREFUSED);
						}
						tcpClient->EndConnect(ar);
					}
					catch (...)
					{
						connected = false;
						delete ar;
						throw;
					}
					finally
					{
						wh->Close();
					}
					delete ar;
				}
			}
			virtual void Close(void) override
			{
				if (connected == true)
				{
					connected = false;
					if (tcpClient != nullptr)
					{
						tcpClient->GetStream()->Close();
						tcpClient->Close();
						delete(tcpClient);
						tcpClient = nullptr;
					}
				}
			}
			virtual void Clear(void) override
			{
				if (tcpClient != nullptr)
					tcpClient->GetStream()->Flush();
			}
	};
}