#pragma once
//*************************************************************************************************
//                                           Form principal
// Data: 14/05/2020
//*************************************************************************************************
#include "Modules.h"
#include "AnalogSignals.h"

constexpr auto TAXA_AMOSTRAGEM = (1 / 1000.0f);

namespace BaseProject 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Configuration;
	using namespace CommDevices;
	using namespace Modules;
	using namespace AnalogSignals;

	/// <summary>
	/// Sumário para MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void) : requestPowerDownVisualAnswer(false)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  stLabelConnection;
	private: System::Windows::Forms::SaveFileDialog^ dlgSaveCSV;
	private: System::Windows::Forms::ToolStripStatusLabel^ stLabelNetConnection;
	private: System::Windows::Forms::TabPage^ tabComm;

	private: System::Windows::Forms::TextBox^ txtMessages;
	private: System::Windows::Forms::Button^ btnTxtClear;
	private: System::Windows::Forms::GroupBox^ gbxSerialConnection;
	private: System::Windows::Forms::ComboBox^ cmboxSerialPorts;
	private: System::Windows::Forms::Button^ btnConnect;
	private: System::Windows::Forms::GroupBox^ gbxNetConnect;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Button^ btnNetConnect;
	private: System::Windows::Forms::TextBox^ txtPort;
	private: System::Windows::Forms::Label^ lblPoint4;
	private: System::Windows::Forms::Label^ lblPoint3;
	private: System::Windows::Forms::Label^ lblPoint2;
	private: System::Windows::Forms::Label^ lblPoint1;
	private: System::Windows::Forms::TextBox^ txtIP4;
	private: System::Windows::Forms::TextBox^ txtIP3;
	private: System::Windows::Forms::TextBox^ txtIP2;
	private: System::Windows::Forms::TextBox^ txtIP1;
	private: System::Windows::Forms::Label^ lblNetConnect;
	private: System::Windows::Forms::TabControl^ tabCtrlApplication;
	private: System::Windows::Forms::TabPage^ tabConfig;
	private: System::Windows::Forms::CheckBox^ cbxSendToRouter;









	private: System::Windows::Forms::GroupBox^ gbxEcho;
	private: System::Windows::Forms::Label^ lblEcho;
	private: System::Windows::Forms::TextBox^ txtSendMessage;
	private: System::Windows::Forms::Button^ btnSendEcho;
	private: System::Windows::Forms::Label^ lblModuleDateTime;
	private: System::Windows::Forms::Button^ btnReadDateTime;
	private: System::Windows::Forms::Button^ btnUpdateDateTime;
	private: System::Windows::Forms::TabPage^ tabSamples;
	private: System::Windows::Forms::Label^ lblSensor6;
	private: System::Windows::Forms::Label^ lblSensor5;
	private: System::Windows::Forms::Label^ lblSensor4;
	private: System::Windows::Forms::Label^ lblSensor3;
	private: System::Windows::Forms::Label^ lblSensor2;
	private: System::Windows::Forms::Label^ lblSensor1;
	private: System::Windows::Forms::Label^ lblLastSampleInstant;







	private: System::Windows::Forms::GroupBox^ gbxRTC;
	private: System::Windows::Forms::GroupBox^ gbxSensor1;

	private: System::Windows::Forms::TextBox^ txtMaxThreshold1;


	private: System::Windows::Forms::Label^ lblMaxThreshold1;

	private: System::Windows::Forms::TextBox^ txtMinThreshold1;

	private: System::Windows::Forms::Label^ lblMinThreshold1;
	private: System::Windows::Forms::Button^ btnSendSensor1Config;
	private: System::Windows::Forms::Button^ btnReadSensor1Config;
	private: System::Windows::Forms::GroupBox^ gbxSensor6;
	private: System::Windows::Forms::Button^ btnSendSensor6Config;


	private: System::Windows::Forms::Button^ btnReadSensor6Config;

	private: System::Windows::Forms::TextBox^ txtMaxThreshold6;

	private: System::Windows::Forms::Label^ lblMaxThreshold6;

	private: System::Windows::Forms::TextBox^ txtMinThreshold6;

	private: System::Windows::Forms::Label^ lblMinThreshold6;



	private: System::Windows::Forms::GroupBox^ gbxSensor5;
private: System::Windows::Forms::Button^ btnSendSensor5Config;


private: System::Windows::Forms::Button^ btnReadSensor5Config;

private: System::Windows::Forms::TextBox^ txtMaxThreshold5;

private: System::Windows::Forms::Label^ lblMaxThreshold5;

private: System::Windows::Forms::TextBox^ txtMinThreshold5;

private: System::Windows::Forms::Label^ lblMinThreshold5;



private: System::Windows::Forms::GroupBox^ gbxSensor4;
private: System::Windows::Forms::Button^ btnSendSensor4Config;


private: System::Windows::Forms::Button^ btnReadSensor4Config;

private: System::Windows::Forms::TextBox^ txtMaxThreshold4;

private: System::Windows::Forms::Label^ lblMaxThreshold4;

private: System::Windows::Forms::TextBox^ txtMinThreshold4;

private: System::Windows::Forms::Label^ lblMinThreshold4;



private: System::Windows::Forms::GroupBox^ gbxSensor3;
private: System::Windows::Forms::Button^ btnSendSensor3Config;


private: System::Windows::Forms::Button^ btnReadSensor3Config;

private: System::Windows::Forms::TextBox^ txtMaxThreshold3;

private: System::Windows::Forms::Label^ lblMaxThreshold3;

private: System::Windows::Forms::TextBox^ txtMinThreshold3;

private: System::Windows::Forms::Label^ lblMinThreshold3;



private: System::Windows::Forms::GroupBox^ gbxSensor2;
private: System::Windows::Forms::Button^ btnSendSensor2Config;


private: System::Windows::Forms::Button^ btnReadSensor2Config;

private: System::Windows::Forms::TextBox^ txtMaxThreshold2;

private: System::Windows::Forms::Label^ lblMaxThreshold2;

private: System::Windows::Forms::TextBox^ txtMinThreshold2;

private: System::Windows::Forms::Label^ lblMinThreshold2;








private: System::Windows::Forms::Button^ btnEnterPowerDown;
private: System::Windows::Forms::Button^ btnSaveConfigs;
private: System::Windows::Forms::ComboBox^ cmbxControl1Operation;
private: System::Windows::Forms::ComboBox^ cmbxControl6Operation;


private: System::Windows::Forms::ComboBox^ cmbxControl5Operation;

private: System::Windows::Forms::ComboBox^ cmbxControl4Operation;

private: System::Windows::Forms::ComboBox^ cmbxControl3Operation;

private: System::Windows::Forms::ComboBox^ cmbxControl2Operation;
private: System::Windows::Forms::GroupBox^ gbxServerMode;
private: System::Windows::Forms::CheckBox^ cbxHaltPowerDown;














	private: System::ComponentModel::IContainer^ components;
	protected:
	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->stLabelConnection = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->stLabelNetConnection = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->dlgSaveCSV = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabComm = (gcnew System::Windows::Forms::TabPage());
			this->gbxEcho = (gcnew System::Windows::Forms::GroupBox());
			this->cbxSendToRouter = (gcnew System::Windows::Forms::CheckBox());
			this->lblEcho = (gcnew System::Windows::Forms::Label());
			this->txtSendMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnSendEcho = (gcnew System::Windows::Forms::Button());
			this->txtMessages = (gcnew System::Windows::Forms::TextBox());
			this->btnTxtClear = (gcnew System::Windows::Forms::Button());
			this->gbxSerialConnection = (gcnew System::Windows::Forms::GroupBox());
			this->cmboxSerialPorts = (gcnew System::Windows::Forms::ComboBox());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->gbxNetConnect = (gcnew System::Windows::Forms::GroupBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnNetConnect = (gcnew System::Windows::Forms::Button());
			this->txtPort = (gcnew System::Windows::Forms::TextBox());
			this->lblPoint4 = (gcnew System::Windows::Forms::Label());
			this->lblPoint3 = (gcnew System::Windows::Forms::Label());
			this->lblPoint2 = (gcnew System::Windows::Forms::Label());
			this->lblPoint1 = (gcnew System::Windows::Forms::Label());
			this->txtIP4 = (gcnew System::Windows::Forms::TextBox());
			this->txtIP3 = (gcnew System::Windows::Forms::TextBox());
			this->txtIP2 = (gcnew System::Windows::Forms::TextBox());
			this->txtIP1 = (gcnew System::Windows::Forms::TextBox());
			this->lblNetConnect = (gcnew System::Windows::Forms::Label());
			this->tabCtrlApplication = (gcnew System::Windows::Forms::TabControl());
			this->tabConfig = (gcnew System::Windows::Forms::TabPage());
			this->gbxServerMode = (gcnew System::Windows::Forms::GroupBox());
			this->cbxHaltPowerDown = (gcnew System::Windows::Forms::CheckBox());
			this->btnEnterPowerDown = (gcnew System::Windows::Forms::Button());
			this->btnSaveConfigs = (gcnew System::Windows::Forms::Button());
			this->gbxSensor6 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbxControl6Operation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSendSensor6Config = (gcnew System::Windows::Forms::Button());
			this->btnReadSensor6Config = (gcnew System::Windows::Forms::Button());
			this->txtMaxThreshold6 = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxThreshold6 = (gcnew System::Windows::Forms::Label());
			this->txtMinThreshold6 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinThreshold6 = (gcnew System::Windows::Forms::Label());
			this->gbxSensor5 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbxControl5Operation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSendSensor5Config = (gcnew System::Windows::Forms::Button());
			this->btnReadSensor5Config = (gcnew System::Windows::Forms::Button());
			this->txtMaxThreshold5 = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxThreshold5 = (gcnew System::Windows::Forms::Label());
			this->txtMinThreshold5 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinThreshold5 = (gcnew System::Windows::Forms::Label());
			this->gbxSensor4 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbxControl4Operation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSendSensor4Config = (gcnew System::Windows::Forms::Button());
			this->btnReadSensor4Config = (gcnew System::Windows::Forms::Button());
			this->txtMaxThreshold4 = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxThreshold4 = (gcnew System::Windows::Forms::Label());
			this->txtMinThreshold4 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinThreshold4 = (gcnew System::Windows::Forms::Label());
			this->gbxSensor3 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbxControl3Operation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSendSensor3Config = (gcnew System::Windows::Forms::Button());
			this->btnReadSensor3Config = (gcnew System::Windows::Forms::Button());
			this->txtMaxThreshold3 = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxThreshold3 = (gcnew System::Windows::Forms::Label());
			this->txtMinThreshold3 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinThreshold3 = (gcnew System::Windows::Forms::Label());
			this->gbxSensor2 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbxControl2Operation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSendSensor2Config = (gcnew System::Windows::Forms::Button());
			this->btnReadSensor2Config = (gcnew System::Windows::Forms::Button());
			this->txtMaxThreshold2 = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxThreshold2 = (gcnew System::Windows::Forms::Label());
			this->txtMinThreshold2 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinThreshold2 = (gcnew System::Windows::Forms::Label());
			this->gbxSensor1 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbxControl1Operation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSendSensor1Config = (gcnew System::Windows::Forms::Button());
			this->btnReadSensor1Config = (gcnew System::Windows::Forms::Button());
			this->txtMaxThreshold1 = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxThreshold1 = (gcnew System::Windows::Forms::Label());
			this->txtMinThreshold1 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinThreshold1 = (gcnew System::Windows::Forms::Label());
			this->gbxRTC = (gcnew System::Windows::Forms::GroupBox());
			this->lblModuleDateTime = (gcnew System::Windows::Forms::Label());
			this->btnUpdateDateTime = (gcnew System::Windows::Forms::Button());
			this->btnReadDateTime = (gcnew System::Windows::Forms::Button());
			this->tabSamples = (gcnew System::Windows::Forms::TabPage());
			this->lblLastSampleInstant = (gcnew System::Windows::Forms::Label());
			this->lblSensor6 = (gcnew System::Windows::Forms::Label());
			this->lblSensor5 = (gcnew System::Windows::Forms::Label());
			this->lblSensor4 = (gcnew System::Windows::Forms::Label());
			this->lblSensor3 = (gcnew System::Windows::Forms::Label());
			this->lblSensor2 = (gcnew System::Windows::Forms::Label());
			this->lblSensor1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1->SuspendLayout();
			this->tabComm->SuspendLayout();
			this->gbxEcho->SuspendLayout();
			this->gbxSerialConnection->SuspendLayout();
			this->gbxNetConnect->SuspendLayout();
			this->tabCtrlApplication->SuspendLayout();
			this->tabConfig->SuspendLayout();
			this->gbxServerMode->SuspendLayout();
			this->gbxSensor6->SuspendLayout();
			this->gbxSensor5->SuspendLayout();
			this->gbxSensor4->SuspendLayout();
			this->gbxSensor3->SuspendLayout();
			this->gbxSensor2->SuspendLayout();
			this->gbxSensor1->SuspendLayout();
			this->gbxRTC->SuspendLayout();
			this->tabSamples->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->stLabelConnection,
					this->stLabelNetConnection
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 639);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 19, 0);
			this->statusStrip1->Size = System::Drawing::Size(920, 26);
			this->statusStrip1->TabIndex = 15;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// stLabelConnection
			// 
			this->stLabelConnection->Name = L"stLabelConnection";
			this->stLabelConnection->Size = System::Drawing::Size(104, 20);
			this->stLabelConnection->Text = L"Desconectado";
			// 
			// stLabelNetConnection
			// 
			this->stLabelNetConnection->Name = L"stLabelNetConnection";
			this->stLabelNetConnection->Size = System::Drawing::Size(151, 20);
			this->stLabelNetConnection->Text = L"toolStripStatusLabel1";
			// 
			// dlgSaveCSV
			// 
			this->dlgSaveCSV->Filter = L"Arquivos CSV | *.csv";
			this->dlgSaveCSV->InitialDirectory = L".";
			this->dlgSaveCSV->Title = L"Salvar pontos atuais";
			// 
			// tabComm
			// 
			this->tabComm->BackColor = System::Drawing::SystemColors::Control;
			this->tabComm->Controls->Add(this->gbxEcho);
			this->tabComm->Controls->Add(this->txtMessages);
			this->tabComm->Controls->Add(this->btnTxtClear);
			this->tabComm->Controls->Add(this->gbxSerialConnection);
			this->tabComm->Controls->Add(this->gbxNetConnect);
			this->tabComm->Location = System::Drawing::Point(4, 25);
			this->tabComm->Margin = System::Windows::Forms::Padding(4);
			this->tabComm->Name = L"tabComm";
			this->tabComm->Padding = System::Windows::Forms::Padding(4);
			this->tabComm->Size = System::Drawing::Size(912, 610);
			this->tabComm->TabIndex = 0;
			this->tabComm->Text = L"Comunicação";
			// 
			// gbxEcho
			// 
			this->gbxEcho->Controls->Add(this->cbxSendToRouter);
			this->gbxEcho->Controls->Add(this->lblEcho);
			this->gbxEcho->Controls->Add(this->txtSendMessage);
			this->gbxEcho->Controls->Add(this->btnSendEcho);
			this->gbxEcho->Location = System::Drawing::Point(7, 166);
			this->gbxEcho->Name = L"gbxEcho";
			this->gbxEcho->Size = System::Drawing::Size(896, 98);
			this->gbxEcho->TabIndex = 31;
			this->gbxEcho->TabStop = false;
			this->gbxEcho->Text = L"Ecoar mensagem";
			// 
			// cbxSendToRouter
			// 
			this->cbxSendToRouter->AutoSize = true;
			this->cbxSendToRouter->Location = System::Drawing::Point(11, 65);
			this->cbxSendToRouter->Name = L"cbxSendToRouter";
			this->cbxSendToRouter->Size = System::Drawing::Size(163, 20);
			this->cbxSendToRouter->TabIndex = 2;
			this->cbxSendToRouter->Text = L"Enviar para o roteador";
			this->cbxSendToRouter->UseVisualStyleBackColor = true;
			// 
			// lblEcho
			// 
			this->lblEcho->AutoSize = true;
			this->lblEcho->Enabled = false;
			this->lblEcho->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEcho->Location = System::Drawing::Point(7, 28);
			this->lblEcho->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblEcho->Name = L"lblEcho";
			this->lblEcho->Size = System::Drawing::Size(99, 20);
			this->lblEcho->TabIndex = 26;
			this->lblEcho->Text = L"Ecoar texto:";
			// 
			// txtSendMessage
			// 
			this->txtSendMessage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtSendMessage->Enabled = false;
			this->txtSendMessage->Location = System::Drawing::Point(119, 25);
			this->txtSendMessage->Margin = System::Windows::Forms::Padding(4);
			this->txtSendMessage->MaxLength = 44;
			this->txtSendMessage->Name = L"txtSendMessage";
			this->txtSendMessage->Size = System::Drawing::Size(659, 22);
			this->txtSendMessage->TabIndex = 3;
			// 
			// btnSendEcho
			// 
			this->btnSendEcho->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSendEcho->Enabled = false;
			this->btnSendEcho->Location = System::Drawing::Point(787, 22);
			this->btnSendEcho->Margin = System::Windows::Forms::Padding(4);
			this->btnSendEcho->Name = L"btnSendEcho";
			this->btnSendEcho->Size = System::Drawing::Size(100, 28);
			this->btnSendEcho->TabIndex = 4;
			this->btnSendEcho->Text = L"Enviar";
			this->btnSendEcho->UseVisualStyleBackColor = true;
			this->btnSendEcho->Click += gcnew System::EventHandler(this, &MainForm::btnSendEcho_Click);
			// 
			// txtMessages
			// 
			this->txtMessages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtMessages->Enabled = false;
			this->txtMessages->Location = System::Drawing::Point(9, 271);
			this->txtMessages->Margin = System::Windows::Forms::Padding(4);
			this->txtMessages->Multiline = true;
			this->txtMessages->Name = L"txtMessages";
			this->txtMessages->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtMessages->Size = System::Drawing::Size(895, 297);
			this->txtMessages->TabIndex = 13;
			// 
			// btnTxtClear
			// 
			this->btnTxtClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnTxtClear->Enabled = false;
			this->btnTxtClear->Location = System::Drawing::Point(741, 575);
			this->btnTxtClear->Name = L"btnTxtClear";
			this->btnTxtClear->Size = System::Drawing::Size(163, 28);
			this->btnTxtClear->TabIndex = 14;
			this->btnTxtClear->Text = L"Limpar caixa de texto";
			this->btnTxtClear->UseVisualStyleBackColor = true;
			this->btnTxtClear->Click += gcnew System::EventHandler(this, &MainForm::btnTxtClear_Click);
			// 
			// gbxSerialConnection
			// 
			this->gbxSerialConnection->Controls->Add(this->cmboxSerialPorts);
			this->gbxSerialConnection->Controls->Add(this->btnConnect);
			this->gbxSerialConnection->Location = System::Drawing::Point(7, 7);
			this->gbxSerialConnection->Name = L"gbxSerialConnection";
			this->gbxSerialConnection->Size = System::Drawing::Size(891, 80);
			this->gbxSerialConnection->TabIndex = 25;
			this->gbxSerialConnection->TabStop = false;
			this->gbxSerialConnection->Text = L"Conexão com a placa por USB";
			// 
			// cmboxSerialPorts
			// 
			this->cmboxSerialPorts->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmboxSerialPorts->FormattingEnabled = true;
			this->cmboxSerialPorts->Location = System::Drawing::Point(18, 33);
			this->cmboxSerialPorts->Margin = System::Windows::Forms::Padding(4);
			this->cmboxSerialPorts->Name = L"cmboxSerialPorts";
			this->cmboxSerialPorts->Size = System::Drawing::Size(207, 24);
			this->cmboxSerialPorts->TabIndex = 0;
			this->cmboxSerialPorts->Click += gcnew System::EventHandler(this, &MainForm::cmboxSerialPorts_Click);
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(234, 33);
			this->btnConnect->Margin = System::Windows::Forms::Padding(4);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(113, 28);
			this->btnConnect->TabIndex = 1;
			this->btnConnect->Text = L"Conectar";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &MainForm::btnConnect_Click);
			// 
			// gbxNetConnect
			// 
			this->gbxNetConnect->Controls->Add(this->btnSearch);
			this->gbxNetConnect->Controls->Add(this->btnNetConnect);
			this->gbxNetConnect->Controls->Add(this->txtPort);
			this->gbxNetConnect->Controls->Add(this->lblPoint4);
			this->gbxNetConnect->Controls->Add(this->lblPoint3);
			this->gbxNetConnect->Controls->Add(this->lblPoint2);
			this->gbxNetConnect->Controls->Add(this->lblPoint1);
			this->gbxNetConnect->Controls->Add(this->txtIP4);
			this->gbxNetConnect->Controls->Add(this->txtIP3);
			this->gbxNetConnect->Controls->Add(this->txtIP2);
			this->gbxNetConnect->Controls->Add(this->txtIP1);
			this->gbxNetConnect->Controls->Add(this->lblNetConnect);
			this->gbxNetConnect->Location = System::Drawing::Point(9, 93);
			this->gbxNetConnect->Name = L"gbxNetConnect";
			this->gbxNetConnect->Size = System::Drawing::Size(891, 67);
			this->gbxNetConnect->TabIndex = 27;
			this->gbxNetConnect->TabStop = false;
			this->gbxNetConnect->Text = L"Conexão wireless com a placa";
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(529, 25);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(175, 23);
			this->btnSearch->TabIndex = 12;
			this->btnSearch->Text = L"Procurar e conectar";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MainForm::btnSearch_Click);
			// 
			// btnNetConnect
			// 
			this->btnNetConnect->Location = System::Drawing::Point(407, 25);
			this->btnNetConnect->Name = L"btnNetConnect";
			this->btnNetConnect->Size = System::Drawing::Size(116, 23);
			this->btnNetConnect->TabIndex = 11;
			this->btnNetConnect->Text = L"Conectar";
			this->btnNetConnect->UseVisualStyleBackColor = true;
			this->btnNetConnect->Click += gcnew System::EventHandler(this, &MainForm::btnNetConnect_Click);
			// 
			// txtPort
			// 
			this->txtPort->Location = System::Drawing::Point(327, 25);
			this->txtPort->Name = L"txtPort";
			this->txtPort->Size = System::Drawing::Size(74, 22);
			this->txtPort->TabIndex = 10;
			// 
			// lblPoint4
			// 
			this->lblPoint4->AutoSize = true;
			this->lblPoint4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint4->Location = System::Drawing::Point(308, 26);
			this->lblPoint4->Name = L"lblPoint4";
			this->lblPoint4->Size = System::Drawing::Size(15, 20);
			this->lblPoint4->TabIndex = 8;
			this->lblPoint4->Text = L":";
			// 
			// lblPoint3
			// 
			this->lblPoint3->AutoSize = true;
			this->lblPoint3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint3->Location = System::Drawing::Point(236, 26);
			this->lblPoint3->Name = L"lblPoint3";
			this->lblPoint3->Size = System::Drawing::Size(14, 20);
			this->lblPoint3->TabIndex = 7;
			this->lblPoint3->Text = L".";
			// 
			// lblPoint2
			// 
			this->lblPoint2->AutoSize = true;
			this->lblPoint2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint2->Location = System::Drawing::Point(165, 26);
			this->lblPoint2->Name = L"lblPoint2";
			this->lblPoint2->Size = System::Drawing::Size(14, 20);
			this->lblPoint2->TabIndex = 6;
			this->lblPoint2->Text = L".";
			// 
			// lblPoint1
			// 
			this->lblPoint1->AutoSize = true;
			this->lblPoint1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint1->Location = System::Drawing::Point(95, 25);
			this->lblPoint1->Name = L"lblPoint1";
			this->lblPoint1->Size = System::Drawing::Size(14, 20);
			this->lblPoint1->TabIndex = 5;
			this->lblPoint1->Text = L".";
			// 
			// txtIP4
			// 
			this->txtIP4->Location = System::Drawing::Point(254, 25);
			this->txtIP4->Name = L"txtIP4";
			this->txtIP4->Size = System::Drawing::Size(50, 22);
			this->txtIP4->TabIndex = 9;
			// 
			// txtIP3
			// 
			this->txtIP3->Location = System::Drawing::Point(183, 25);
			this->txtIP3->Name = L"txtIP3";
			this->txtIP3->Size = System::Drawing::Size(50, 22);
			this->txtIP3->TabIndex = 8;
			// 
			// txtIP2
			// 
			this->txtIP2->Location = System::Drawing::Point(112, 25);
			this->txtIP2->Name = L"txtIP2";
			this->txtIP2->Size = System::Drawing::Size(50, 22);
			this->txtIP2->TabIndex = 7;
			// 
			// txtIP1
			// 
			this->txtIP1->Location = System::Drawing::Point(43, 25);
			this->txtIP1->Name = L"txtIP1";
			this->txtIP1->Size = System::Drawing::Size(50, 22);
			this->txtIP1->TabIndex = 6;
			// 
			// lblNetConnect
			// 
			this->lblNetConnect->AutoSize = true;
			this->lblNetConnect->Location = System::Drawing::Point(15, 28);
			this->lblNetConnect->Name = L"lblNetConnect";
			this->lblNetConnect->Size = System::Drawing::Size(22, 16);
			this->lblNetConnect->TabIndex = 0;
			this->lblNetConnect->Text = L"IP:";
			// 
			// tabCtrlApplication
			// 
			this->tabCtrlApplication->Controls->Add(this->tabComm);
			this->tabCtrlApplication->Controls->Add(this->tabConfig);
			this->tabCtrlApplication->Controls->Add(this->tabSamples);
			this->tabCtrlApplication->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabCtrlApplication->Location = System::Drawing::Point(0, 0);
			this->tabCtrlApplication->Margin = System::Windows::Forms::Padding(4);
			this->tabCtrlApplication->Name = L"tabCtrlApplication";
			this->tabCtrlApplication->SelectedIndex = 0;
			this->tabCtrlApplication->Size = System::Drawing::Size(920, 639);
			this->tabCtrlApplication->TabIndex = 16;
			this->tabCtrlApplication->TabStop = false;
			// 
			// tabConfig
			// 
			this->tabConfig->BackColor = System::Drawing::SystemColors::Control;
			this->tabConfig->Controls->Add(this->gbxServerMode);
			this->tabConfig->Controls->Add(this->btnEnterPowerDown);
			this->tabConfig->Controls->Add(this->btnSaveConfigs);
			this->tabConfig->Controls->Add(this->gbxSensor6);
			this->tabConfig->Controls->Add(this->gbxSensor5);
			this->tabConfig->Controls->Add(this->gbxSensor4);
			this->tabConfig->Controls->Add(this->gbxSensor3);
			this->tabConfig->Controls->Add(this->gbxSensor2);
			this->tabConfig->Controls->Add(this->gbxSensor1);
			this->tabConfig->Controls->Add(this->gbxRTC);
			this->tabConfig->Location = System::Drawing::Point(4, 25);
			this->tabConfig->Margin = System::Windows::Forms::Padding(4);
			this->tabConfig->Name = L"tabConfig";
			this->tabConfig->Size = System::Drawing::Size(912, 610);
			this->tabConfig->TabIndex = 2;
			this->tabConfig->Text = L"Configuração";
			// 
			// gbxServerMode
			// 
			this->gbxServerMode->Controls->Add(this->cbxHaltPowerDown);
			this->gbxServerMode->Location = System::Drawing::Point(8, 3);
			this->gbxServerMode->Name = L"gbxServerMode";
			this->gbxServerMode->Size = System::Drawing::Size(896, 62);
			this->gbxServerMode->TabIndex = 14;
			this->gbxServerMode->TabStop = false;
			this->gbxServerMode->Text = L"Modo Servidor";
			// 
			// cbxHaltPowerDown
			// 
			this->cbxHaltPowerDown->AutoSize = true;
			this->cbxHaltPowerDown->Location = System::Drawing::Point(6, 26);
			this->cbxHaltPowerDown->Name = L"cbxHaltPowerDown";
			this->cbxHaltPowerDown->Size = System::Drawing::Size(278, 20);
			this->cbxHaltPowerDown->TabIndex = 0;
			this->cbxHaltPowerDown->Text = L"Manter módulo ligado para configurações";
			this->cbxHaltPowerDown->UseVisualStyleBackColor = true;
			this->cbxHaltPowerDown->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxHaltPowerDown_CheckedChanged);
			// 
			// btnEnterPowerDown
			// 
			this->btnEnterPowerDown->Location = System::Drawing::Point(467, 573);
			this->btnEnterPowerDown->Name = L"btnEnterPowerDown";
			this->btnEnterPowerDown->Size = System::Drawing::Size(217, 23);
			this->btnEnterPowerDown->TabIndex = 13;
			this->btnEnterPowerDown->Text = L"Entrar em modo Power Down";
			this->btnEnterPowerDown->UseVisualStyleBackColor = true;
			this->btnEnterPowerDown->Click += gcnew System::EventHandler(this, &MainForm::btnEnterPowerDown_Click);
			// 
			// btnSaveConfigs
			// 
			this->btnSaveConfigs->Location = System::Drawing::Point(257, 573);
			this->btnSaveConfigs->Name = L"btnSaveConfigs";
			this->btnSaveConfigs->Size = System::Drawing::Size(204, 23);
			this->btnSaveConfigs->TabIndex = 12;
			this->btnSaveConfigs->Text = L"Salvar configurações";
			this->btnSaveConfigs->UseVisualStyleBackColor = true;
			this->btnSaveConfigs->Click += gcnew System::EventHandler(this, &MainForm::btnSaveConfigs_Click);
			// 
			// gbxSensor6
			// 
			this->gbxSensor6->Controls->Add(this->cmbxControl6Operation);
			this->gbxSensor6->Controls->Add(this->btnSendSensor6Config);
			this->gbxSensor6->Controls->Add(this->btnReadSensor6Config);
			this->gbxSensor6->Controls->Add(this->txtMaxThreshold6);
			this->gbxSensor6->Controls->Add(this->lblMaxThreshold6);
			this->gbxSensor6->Controls->Add(this->txtMinThreshold6);
			this->gbxSensor6->Controls->Add(this->lblMinThreshold6);
			this->gbxSensor6->Location = System::Drawing::Point(8, 429);
			this->gbxSensor6->Name = L"gbxSensor6";
			this->gbxSensor6->Size = System::Drawing::Size(896, 53);
			this->gbxSensor6->TabIndex = 10;
			this->gbxSensor6->TabStop = false;
			this->gbxSensor6->Text = L"Sensor 6";
			// 
			// cmbxControl6Operation
			// 
			this->cmbxControl6Operation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbxControl6Operation->FormattingEnabled = true;
			this->cmbxControl6Operation->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Desligado", L"Sensor ligado", L"Valvula controlada por sensor",
					L"Forçar válvula ligada", L"Forçar válvula desligada"
			});
			this->cmbxControl6Operation->Location = System::Drawing::Point(6, 17);
			this->cmbxControl6Operation->Name = L"cmbxControl6Operation";
			this->cmbxControl6Operation->Size = System::Drawing::Size(185, 24);
			this->cmbxControl6Operation->TabIndex = 8;
			// 
			// btnSendSensor6Config
			// 
			this->btnSendSensor6Config->Location = System::Drawing::Point(781, 17);
			this->btnSendSensor6Config->Name = L"btnSendSensor6Config";
			this->btnSendSensor6Config->Size = System::Drawing::Size(109, 23);
			this->btnSendSensor6Config->TabIndex = 6;
			this->btnSendSensor6Config->Text = L"Enviar valores";
			this->btnSendSensor6Config->UseVisualStyleBackColor = true;
			this->btnSendSensor6Config->Click += gcnew System::EventHandler(this, &MainForm::btnSendSensor6Config_Click);
			// 
			// btnReadSensor6Config
			// 
			this->btnReadSensor6Config->Location = System::Drawing::Point(682, 17);
			this->btnReadSensor6Config->Name = L"btnReadSensor6Config";
			this->btnReadSensor6Config->Size = System::Drawing::Size(93, 23);
			this->btnReadSensor6Config->TabIndex = 5;
			this->btnReadSensor6Config->Text = L"Ler valores";
			this->btnReadSensor6Config->UseVisualStyleBackColor = true;
			this->btnReadSensor6Config->Click += gcnew System::EventHandler(this, &MainForm::btnReadSensor6Config_Click);
			// 
			// txtMaxThreshold6
			// 
			this->txtMaxThreshold6->Location = System::Drawing::Point(597, 17);
			this->txtMaxThreshold6->Name = L"txtMaxThreshold6";
			this->txtMaxThreshold6->Size = System::Drawing::Size(80, 22);
			this->txtMaxThreshold6->TabIndex = 4;
			// 
			// lblMaxThreshold6
			// 
			this->lblMaxThreshold6->AutoSize = true;
			this->lblMaxThreshold6->Location = System::Drawing::Point(436, 20);
			this->lblMaxThreshold6->Name = L"lblMaxThreshold6";
			this->lblMaxThreshold6->Size = System::Drawing::Size(155, 16);
			this->lblMaxThreshold6->TabIndex = 3;
			this->lblMaxThreshold6->Text = L"Limite superior de leitura:";
			// 
			// txtMinThreshold6
			// 
			this->txtMinThreshold6->Location = System::Drawing::Point(350, 17);
			this->txtMinThreshold6->Name = L"txtMinThreshold6";
			this->txtMinThreshold6->Size = System::Drawing::Size(80, 22);
			this->txtMinThreshold6->TabIndex = 2;
			// 
			// lblMinThreshold6
			// 
			this->lblMinThreshold6->AutoSize = true;
			this->lblMinThreshold6->Location = System::Drawing::Point(198, 20);
			this->lblMinThreshold6->Name = L"lblMinThreshold6";
			this->lblMinThreshold6->Size = System::Drawing::Size(146, 16);
			this->lblMinThreshold6->TabIndex = 1;
			this->lblMinThreshold6->Text = L"Limite inferior de leitura:";
			// 
			// gbxSensor5
			// 
			this->gbxSensor5->Controls->Add(this->cmbxControl5Operation);
			this->gbxSensor5->Controls->Add(this->btnSendSensor5Config);
			this->gbxSensor5->Controls->Add(this->btnReadSensor5Config);
			this->gbxSensor5->Controls->Add(this->txtMaxThreshold5);
			this->gbxSensor5->Controls->Add(this->lblMaxThreshold5);
			this->gbxSensor5->Controls->Add(this->txtMinThreshold5);
			this->gbxSensor5->Controls->Add(this->lblMinThreshold5);
			this->gbxSensor5->Location = System::Drawing::Point(8, 370);
			this->gbxSensor5->Name = L"gbxSensor5";
			this->gbxSensor5->Size = System::Drawing::Size(896, 53);
			this->gbxSensor5->TabIndex = 9;
			this->gbxSensor5->TabStop = false;
			this->gbxSensor5->Text = L"Sensor 5";
			// 
			// cmbxControl5Operation
			// 
			this->cmbxControl5Operation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbxControl5Operation->FormattingEnabled = true;
			this->cmbxControl5Operation->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Desligado", L"Sensor ligado", L"Valvula controlada por sensor",
					L"Forçar válvula ligada", L"Forçar válvula desligada"
			});
			this->cmbxControl5Operation->Location = System::Drawing::Point(6, 17);
			this->cmbxControl5Operation->Name = L"cmbxControl5Operation";
			this->cmbxControl5Operation->Size = System::Drawing::Size(185, 24);
			this->cmbxControl5Operation->TabIndex = 8;
			// 
			// btnSendSensor5Config
			// 
			this->btnSendSensor5Config->Location = System::Drawing::Point(781, 17);
			this->btnSendSensor5Config->Name = L"btnSendSensor5Config";
			this->btnSendSensor5Config->Size = System::Drawing::Size(109, 23);
			this->btnSendSensor5Config->TabIndex = 6;
			this->btnSendSensor5Config->Text = L"Enviar valores";
			this->btnSendSensor5Config->UseVisualStyleBackColor = true;
			this->btnSendSensor5Config->Click += gcnew System::EventHandler(this, &MainForm::btnSendSensor5Config_Click);
			// 
			// btnReadSensor5Config
			// 
			this->btnReadSensor5Config->Location = System::Drawing::Point(682, 17);
			this->btnReadSensor5Config->Name = L"btnReadSensor5Config";
			this->btnReadSensor5Config->Size = System::Drawing::Size(93, 23);
			this->btnReadSensor5Config->TabIndex = 5;
			this->btnReadSensor5Config->Text = L"Ler valores";
			this->btnReadSensor5Config->UseVisualStyleBackColor = true;
			this->btnReadSensor5Config->Click += gcnew System::EventHandler(this, &MainForm::btnReadSensor5Config_Click);
			// 
			// txtMaxThreshold5
			// 
			this->txtMaxThreshold5->Location = System::Drawing::Point(597, 17);
			this->txtMaxThreshold5->Name = L"txtMaxThreshold5";
			this->txtMaxThreshold5->Size = System::Drawing::Size(80, 22);
			this->txtMaxThreshold5->TabIndex = 4;
			// 
			// lblMaxThreshold5
			// 
			this->lblMaxThreshold5->AutoSize = true;
			this->lblMaxThreshold5->Location = System::Drawing::Point(436, 20);
			this->lblMaxThreshold5->Name = L"lblMaxThreshold5";
			this->lblMaxThreshold5->Size = System::Drawing::Size(155, 16);
			this->lblMaxThreshold5->TabIndex = 3;
			this->lblMaxThreshold5->Text = L"Limite superior de leitura:";
			// 
			// txtMinThreshold5
			// 
			this->txtMinThreshold5->Location = System::Drawing::Point(350, 17);
			this->txtMinThreshold5->Name = L"txtMinThreshold5";
			this->txtMinThreshold5->Size = System::Drawing::Size(80, 22);
			this->txtMinThreshold5->TabIndex = 2;
			// 
			// lblMinThreshold5
			// 
			this->lblMinThreshold5->AutoSize = true;
			this->lblMinThreshold5->Location = System::Drawing::Point(198, 20);
			this->lblMinThreshold5->Name = L"lblMinThreshold5";
			this->lblMinThreshold5->Size = System::Drawing::Size(146, 16);
			this->lblMinThreshold5->TabIndex = 1;
			this->lblMinThreshold5->Text = L"Limite inferior de leitura:";
			// 
			// gbxSensor4
			// 
			this->gbxSensor4->Controls->Add(this->cmbxControl4Operation);
			this->gbxSensor4->Controls->Add(this->btnSendSensor4Config);
			this->gbxSensor4->Controls->Add(this->btnReadSensor4Config);
			this->gbxSensor4->Controls->Add(this->txtMaxThreshold4);
			this->gbxSensor4->Controls->Add(this->lblMaxThreshold4);
			this->gbxSensor4->Controls->Add(this->txtMinThreshold4);
			this->gbxSensor4->Controls->Add(this->lblMinThreshold4);
			this->gbxSensor4->Location = System::Drawing::Point(8, 311);
			this->gbxSensor4->Name = L"gbxSensor4";
			this->gbxSensor4->Size = System::Drawing::Size(896, 53);
			this->gbxSensor4->TabIndex = 8;
			this->gbxSensor4->TabStop = false;
			this->gbxSensor4->Text = L"Sensor 4";
			// 
			// cmbxControl4Operation
			// 
			this->cmbxControl4Operation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbxControl4Operation->FormattingEnabled = true;
			this->cmbxControl4Operation->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Desligado", L"Sensor ligado", L"Valvula controlada por sensor",
					L"Forçar válvula ligada", L"Forçar válvula desligada"
			});
			this->cmbxControl4Operation->Location = System::Drawing::Point(6, 19);
			this->cmbxControl4Operation->Name = L"cmbxControl4Operation";
			this->cmbxControl4Operation->Size = System::Drawing::Size(185, 24);
			this->cmbxControl4Operation->TabIndex = 8;
			// 
			// btnSendSensor4Config
			// 
			this->btnSendSensor4Config->Location = System::Drawing::Point(781, 17);
			this->btnSendSensor4Config->Name = L"btnSendSensor4Config";
			this->btnSendSensor4Config->Size = System::Drawing::Size(109, 23);
			this->btnSendSensor4Config->TabIndex = 6;
			this->btnSendSensor4Config->Text = L"Enviar valores";
			this->btnSendSensor4Config->UseVisualStyleBackColor = true;
			this->btnSendSensor4Config->Click += gcnew System::EventHandler(this, &MainForm::btnSendSensor4Config_Click);
			// 
			// btnReadSensor4Config
			// 
			this->btnReadSensor4Config->Location = System::Drawing::Point(682, 17);
			this->btnReadSensor4Config->Name = L"btnReadSensor4Config";
			this->btnReadSensor4Config->Size = System::Drawing::Size(93, 23);
			this->btnReadSensor4Config->TabIndex = 5;
			this->btnReadSensor4Config->Text = L"Ler valores";
			this->btnReadSensor4Config->UseVisualStyleBackColor = true;
			this->btnReadSensor4Config->Click += gcnew System::EventHandler(this, &MainForm::btnReadSensor4Config_Click);
			// 
			// txtMaxThreshold4
			// 
			this->txtMaxThreshold4->Location = System::Drawing::Point(597, 17);
			this->txtMaxThreshold4->Name = L"txtMaxThreshold4";
			this->txtMaxThreshold4->Size = System::Drawing::Size(80, 22);
			this->txtMaxThreshold4->TabIndex = 4;
			// 
			// lblMaxThreshold4
			// 
			this->lblMaxThreshold4->AutoSize = true;
			this->lblMaxThreshold4->Location = System::Drawing::Point(436, 20);
			this->lblMaxThreshold4->Name = L"lblMaxThreshold4";
			this->lblMaxThreshold4->Size = System::Drawing::Size(155, 16);
			this->lblMaxThreshold4->TabIndex = 3;
			this->lblMaxThreshold4->Text = L"Limite superior de leitura:";
			// 
			// txtMinThreshold4
			// 
			this->txtMinThreshold4->Location = System::Drawing::Point(350, 17);
			this->txtMinThreshold4->Name = L"txtMinThreshold4";
			this->txtMinThreshold4->Size = System::Drawing::Size(80, 22);
			this->txtMinThreshold4->TabIndex = 2;
			// 
			// lblMinThreshold4
			// 
			this->lblMinThreshold4->AutoSize = true;
			this->lblMinThreshold4->Location = System::Drawing::Point(198, 20);
			this->lblMinThreshold4->Name = L"lblMinThreshold4";
			this->lblMinThreshold4->Size = System::Drawing::Size(146, 16);
			this->lblMinThreshold4->TabIndex = 1;
			this->lblMinThreshold4->Text = L"Limite inferior de leitura:";
			// 
			// gbxSensor3
			// 
			this->gbxSensor3->Controls->Add(this->cmbxControl3Operation);
			this->gbxSensor3->Controls->Add(this->btnSendSensor3Config);
			this->gbxSensor3->Controls->Add(this->btnReadSensor3Config);
			this->gbxSensor3->Controls->Add(this->txtMaxThreshold3);
			this->gbxSensor3->Controls->Add(this->lblMaxThreshold3);
			this->gbxSensor3->Controls->Add(this->txtMinThreshold3);
			this->gbxSensor3->Controls->Add(this->lblMinThreshold3);
			this->gbxSensor3->Location = System::Drawing::Point(8, 252);
			this->gbxSensor3->Name = L"gbxSensor3";
			this->gbxSensor3->Size = System::Drawing::Size(896, 53);
			this->gbxSensor3->TabIndex = 7;
			this->gbxSensor3->TabStop = false;
			this->gbxSensor3->Text = L"Sensor 3";
			// 
			// cmbxControl3Operation
			// 
			this->cmbxControl3Operation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbxControl3Operation->FormattingEnabled = true;
			this->cmbxControl3Operation->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Desligado", L"Sensor ligado", L"Valvula controlada por sensor",
					L"Forçar válvula ligada", L"Forçar válvula desligada"
			});
			this->cmbxControl3Operation->Location = System::Drawing::Point(6, 18);
			this->cmbxControl3Operation->Name = L"cmbxControl3Operation";
			this->cmbxControl3Operation->Size = System::Drawing::Size(185, 24);
			this->cmbxControl3Operation->TabIndex = 8;
			// 
			// btnSendSensor3Config
			// 
			this->btnSendSensor3Config->Location = System::Drawing::Point(781, 17);
			this->btnSendSensor3Config->Name = L"btnSendSensor3Config";
			this->btnSendSensor3Config->Size = System::Drawing::Size(109, 23);
			this->btnSendSensor3Config->TabIndex = 6;
			this->btnSendSensor3Config->Text = L"Enviar valores";
			this->btnSendSensor3Config->UseVisualStyleBackColor = true;
			this->btnSendSensor3Config->Click += gcnew System::EventHandler(this, &MainForm::btnSendSensor3Config_Click);
			// 
			// btnReadSensor3Config
			// 
			this->btnReadSensor3Config->Location = System::Drawing::Point(682, 17);
			this->btnReadSensor3Config->Name = L"btnReadSensor3Config";
			this->btnReadSensor3Config->Size = System::Drawing::Size(93, 23);
			this->btnReadSensor3Config->TabIndex = 5;
			this->btnReadSensor3Config->Text = L"Ler valores";
			this->btnReadSensor3Config->UseVisualStyleBackColor = true;
			this->btnReadSensor3Config->Click += gcnew System::EventHandler(this, &MainForm::btnReadSensor3Config_Click);
			// 
			// txtMaxThreshold3
			// 
			this->txtMaxThreshold3->Location = System::Drawing::Point(597, 17);
			this->txtMaxThreshold3->Name = L"txtMaxThreshold3";
			this->txtMaxThreshold3->Size = System::Drawing::Size(80, 22);
			this->txtMaxThreshold3->TabIndex = 4;
			// 
			// lblMaxThreshold3
			// 
			this->lblMaxThreshold3->AutoSize = true;
			this->lblMaxThreshold3->Location = System::Drawing::Point(436, 20);
			this->lblMaxThreshold3->Name = L"lblMaxThreshold3";
			this->lblMaxThreshold3->Size = System::Drawing::Size(155, 16);
			this->lblMaxThreshold3->TabIndex = 3;
			this->lblMaxThreshold3->Text = L"Limite superior de leitura:";
			// 
			// txtMinThreshold3
			// 
			this->txtMinThreshold3->Location = System::Drawing::Point(350, 17);
			this->txtMinThreshold3->Name = L"txtMinThreshold3";
			this->txtMinThreshold3->Size = System::Drawing::Size(80, 22);
			this->txtMinThreshold3->TabIndex = 2;
			// 
			// lblMinThreshold3
			// 
			this->lblMinThreshold3->AutoSize = true;
			this->lblMinThreshold3->Location = System::Drawing::Point(197, 20);
			this->lblMinThreshold3->Name = L"lblMinThreshold3";
			this->lblMinThreshold3->Size = System::Drawing::Size(146, 16);
			this->lblMinThreshold3->TabIndex = 1;
			this->lblMinThreshold3->Text = L"Limite inferior de leitura:";
			// 
			// gbxSensor2
			// 
			this->gbxSensor2->Controls->Add(this->cmbxControl2Operation);
			this->gbxSensor2->Controls->Add(this->btnSendSensor2Config);
			this->gbxSensor2->Controls->Add(this->btnReadSensor2Config);
			this->gbxSensor2->Controls->Add(this->txtMaxThreshold2);
			this->gbxSensor2->Controls->Add(this->lblMaxThreshold2);
			this->gbxSensor2->Controls->Add(this->txtMinThreshold2);
			this->gbxSensor2->Controls->Add(this->lblMinThreshold2);
			this->gbxSensor2->Location = System::Drawing::Point(8, 193);
			this->gbxSensor2->Name = L"gbxSensor2";
			this->gbxSensor2->Size = System::Drawing::Size(896, 53);
			this->gbxSensor2->TabIndex = 5;
			this->gbxSensor2->TabStop = false;
			this->gbxSensor2->Text = L"Sensor 2";
			// 
			// cmbxControl2Operation
			// 
			this->cmbxControl2Operation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbxControl2Operation->FormattingEnabled = true;
			this->cmbxControl2Operation->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Desligado", L"Sensor ligado", L"Valvula controlada por sensor",
					L"Forçar válvula ligada", L"Forçar válvula desligada"
			});
			this->cmbxControl2Operation->Location = System::Drawing::Point(6, 19);
			this->cmbxControl2Operation->Name = L"cmbxControl2Operation";
			this->cmbxControl2Operation->Size = System::Drawing::Size(185, 24);
			this->cmbxControl2Operation->TabIndex = 8;
			// 
			// btnSendSensor2Config
			// 
			this->btnSendSensor2Config->Location = System::Drawing::Point(781, 17);
			this->btnSendSensor2Config->Name = L"btnSendSensor2Config";
			this->btnSendSensor2Config->Size = System::Drawing::Size(109, 23);
			this->btnSendSensor2Config->TabIndex = 6;
			this->btnSendSensor2Config->Text = L"Enviar valores";
			this->btnSendSensor2Config->UseVisualStyleBackColor = true;
			this->btnSendSensor2Config->Click += gcnew System::EventHandler(this, &MainForm::btnSendSensor2Config_Click);
			// 
			// btnReadSensor2Config
			// 
			this->btnReadSensor2Config->Location = System::Drawing::Point(682, 17);
			this->btnReadSensor2Config->Name = L"btnReadSensor2Config";
			this->btnReadSensor2Config->Size = System::Drawing::Size(93, 23);
			this->btnReadSensor2Config->TabIndex = 5;
			this->btnReadSensor2Config->Text = L"Ler valores";
			this->btnReadSensor2Config->UseVisualStyleBackColor = true;
			this->btnReadSensor2Config->Click += gcnew System::EventHandler(this, &MainForm::btnReadSensor2Config_Click);
			// 
			// txtMaxThreshold2
			// 
			this->txtMaxThreshold2->Location = System::Drawing::Point(596, 19);
			this->txtMaxThreshold2->Name = L"txtMaxThreshold2";
			this->txtMaxThreshold2->Size = System::Drawing::Size(80, 22);
			this->txtMaxThreshold2->TabIndex = 4;
			// 
			// lblMaxThreshold2
			// 
			this->lblMaxThreshold2->AutoSize = true;
			this->lblMaxThreshold2->Location = System::Drawing::Point(435, 22);
			this->lblMaxThreshold2->Name = L"lblMaxThreshold2";
			this->lblMaxThreshold2->Size = System::Drawing::Size(155, 16);
			this->lblMaxThreshold2->TabIndex = 3;
			this->lblMaxThreshold2->Text = L"Limite superior de leitura:";
			// 
			// txtMinThreshold2
			// 
			this->txtMinThreshold2->Location = System::Drawing::Point(349, 19);
			this->txtMinThreshold2->Name = L"txtMinThreshold2";
			this->txtMinThreshold2->Size = System::Drawing::Size(80, 22);
			this->txtMinThreshold2->TabIndex = 2;
			// 
			// lblMinThreshold2
			// 
			this->lblMinThreshold2->AutoSize = true;
			this->lblMinThreshold2->Location = System::Drawing::Point(197, 20);
			this->lblMinThreshold2->Name = L"lblMinThreshold2";
			this->lblMinThreshold2->Size = System::Drawing::Size(146, 16);
			this->lblMinThreshold2->TabIndex = 1;
			this->lblMinThreshold2->Text = L"Limite inferior de leitura:";
			// 
			// gbxSensor1
			// 
			this->gbxSensor1->Controls->Add(this->cmbxControl1Operation);
			this->gbxSensor1->Controls->Add(this->btnSendSensor1Config);
			this->gbxSensor1->Controls->Add(this->btnReadSensor1Config);
			this->gbxSensor1->Controls->Add(this->txtMaxThreshold1);
			this->gbxSensor1->Controls->Add(this->lblMaxThreshold1);
			this->gbxSensor1->Controls->Add(this->txtMinThreshold1);
			this->gbxSensor1->Controls->Add(this->lblMinThreshold1);
			this->gbxSensor1->Location = System::Drawing::Point(8, 134);
			this->gbxSensor1->Name = L"gbxSensor1";
			this->gbxSensor1->Size = System::Drawing::Size(896, 53);
			this->gbxSensor1->TabIndex = 4;
			this->gbxSensor1->TabStop = false;
			this->gbxSensor1->Text = L"Sensor 1";
			// 
			// cmbxControl1Operation
			// 
			this->cmbxControl1Operation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbxControl1Operation->FormattingEnabled = true;
			this->cmbxControl1Operation->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Desligado", L"Sensor ligado", L"Valvula controlada por sensor",
					L"Forçar válvula ligada", L"Forçar válvula desligada"
			});
			this->cmbxControl1Operation->Location = System::Drawing::Point(6, 19);
			this->cmbxControl1Operation->Name = L"cmbxControl1Operation";
			this->cmbxControl1Operation->Size = System::Drawing::Size(185, 24);
			this->cmbxControl1Operation->TabIndex = 7;
			// 
			// btnSendSensor1Config
			// 
			this->btnSendSensor1Config->Location = System::Drawing::Point(781, 17);
			this->btnSendSensor1Config->Name = L"btnSendSensor1Config";
			this->btnSendSensor1Config->Size = System::Drawing::Size(109, 23);
			this->btnSendSensor1Config->TabIndex = 6;
			this->btnSendSensor1Config->Text = L"Enviar valores";
			this->btnSendSensor1Config->UseVisualStyleBackColor = true;
			this->btnSendSensor1Config->Click += gcnew System::EventHandler(this, &MainForm::btnSendSensor1Config_Click);
			// 
			// btnReadSensor1Config
			// 
			this->btnReadSensor1Config->Location = System::Drawing::Point(682, 17);
			this->btnReadSensor1Config->Name = L"btnReadSensor1Config";
			this->btnReadSensor1Config->Size = System::Drawing::Size(93, 23);
			this->btnReadSensor1Config->TabIndex = 5;
			this->btnReadSensor1Config->Text = L"Ler valores";
			this->btnReadSensor1Config->UseVisualStyleBackColor = true;
			this->btnReadSensor1Config->Click += gcnew System::EventHandler(this, &MainForm::btnReadSensor1Config_Click);
			// 
			// txtMaxThreshold1
			// 
			this->txtMaxThreshold1->Location = System::Drawing::Point(596, 17);
			this->txtMaxThreshold1->Name = L"txtMaxThreshold1";
			this->txtMaxThreshold1->Size = System::Drawing::Size(80, 22);
			this->txtMaxThreshold1->TabIndex = 4;
			// 
			// lblMaxThreshold1
			// 
			this->lblMaxThreshold1->AutoSize = true;
			this->lblMaxThreshold1->Location = System::Drawing::Point(435, 20);
			this->lblMaxThreshold1->Name = L"lblMaxThreshold1";
			this->lblMaxThreshold1->Size = System::Drawing::Size(155, 16);
			this->lblMaxThreshold1->TabIndex = 3;
			this->lblMaxThreshold1->Text = L"Limite superior de leitura:";
			// 
			// txtMinThreshold1
			// 
			this->txtMinThreshold1->Location = System::Drawing::Point(349, 18);
			this->txtMinThreshold1->Name = L"txtMinThreshold1";
			this->txtMinThreshold1->Size = System::Drawing::Size(80, 22);
			this->txtMinThreshold1->TabIndex = 2;
			// 
			// lblMinThreshold1
			// 
			this->lblMinThreshold1->AutoSize = true;
			this->lblMinThreshold1->Location = System::Drawing::Point(197, 20);
			this->lblMinThreshold1->Name = L"lblMinThreshold1";
			this->lblMinThreshold1->Size = System::Drawing::Size(146, 16);
			this->lblMinThreshold1->TabIndex = 1;
			this->lblMinThreshold1->Text = L"Limite inferior de leitura:";
			// 
			// gbxRTC
			// 
			this->gbxRTC->Controls->Add(this->lblModuleDateTime);
			this->gbxRTC->Controls->Add(this->btnUpdateDateTime);
			this->gbxRTC->Controls->Add(this->btnReadDateTime);
			this->gbxRTC->Location = System::Drawing::Point(8, 71);
			this->gbxRTC->Name = L"gbxRTC";
			this->gbxRTC->Size = System::Drawing::Size(896, 57);
			this->gbxRTC->TabIndex = 3;
			this->gbxRTC->TabStop = false;
			this->gbxRTC->Text = L"RTC";
			// 
			// lblModuleDateTime
			// 
			this->lblModuleDateTime->AutoSize = true;
			this->lblModuleDateTime->Location = System::Drawing::Point(17, 24);
			this->lblModuleDateTime->Name = L"lblModuleDateTime";
			this->lblModuleDateTime->Size = System::Drawing::Size(208, 16);
			this->lblModuleDateTime->TabIndex = 0;
			this->lblModuleDateTime->Text = L"Data/Hora do módulo: --/--/-- --:--:--";
			// 
			// btnUpdateDateTime
			// 
			this->btnUpdateDateTime->Location = System::Drawing::Point(483, 21);
			this->btnUpdateDateTime->Name = L"btnUpdateDateTime";
			this->btnUpdateDateTime->Size = System::Drawing::Size(75, 23);
			this->btnUpdateDateTime->TabIndex = 2;
			this->btnUpdateDateTime->Text = L"Atualizar";
			this->btnUpdateDateTime->UseVisualStyleBackColor = true;
			this->btnUpdateDateTime->Click += gcnew System::EventHandler(this, &MainForm::btnUpdateDateTime_Click);
			// 
			// btnReadDateTime
			// 
			this->btnReadDateTime->Location = System::Drawing::Point(402, 21);
			this->btnReadDateTime->Name = L"btnReadDateTime";
			this->btnReadDateTime->Size = System::Drawing::Size(75, 23);
			this->btnReadDateTime->TabIndex = 1;
			this->btnReadDateTime->Text = L"Ler";
			this->btnReadDateTime->UseVisualStyleBackColor = true;
			this->btnReadDateTime->Click += gcnew System::EventHandler(this, &MainForm::btnReadDateTime_Click);
			// 
			// tabSamples
			// 
			this->tabSamples->BackColor = System::Drawing::SystemColors::Control;
			this->tabSamples->Controls->Add(this->lblLastSampleInstant);
			this->tabSamples->Controls->Add(this->lblSensor6);
			this->tabSamples->Controls->Add(this->lblSensor5);
			this->tabSamples->Controls->Add(this->lblSensor4);
			this->tabSamples->Controls->Add(this->lblSensor3);
			this->tabSamples->Controls->Add(this->lblSensor2);
			this->tabSamples->Controls->Add(this->lblSensor1);
			this->tabSamples->Location = System::Drawing::Point(4, 25);
			this->tabSamples->Name = L"tabSamples";
			this->tabSamples->Size = System::Drawing::Size(912, 610);
			this->tabSamples->TabIndex = 3;
			this->tabSamples->Text = L"Leituras";
			// 
			// lblLastSampleInstant
			// 
			this->lblLastSampleInstant->AutoSize = true;
			this->lblLastSampleInstant->Location = System::Drawing::Point(8, 11);
			this->lblLastSampleInstant->Name = L"lblLastSampleInstant";
			this->lblLastSampleInstant->Size = System::Drawing::Size(168, 16);
			this->lblLastSampleInstant->TabIndex = 7;
			this->lblLastSampleInstant->Text = L"Última amostra: --/--/-- --:--:--";
			// 
			// lblSensor6
			// 
			this->lblSensor6->AutoSize = true;
			this->lblSensor6->Location = System::Drawing::Point(391, 92);
			this->lblSensor6->Name = L"lblSensor6";
			this->lblSensor6->Size = System::Drawing::Size(74, 16);
			this->lblSensor6->TabIndex = 6;
			this->lblSensor6->Text = L"Sensor 6: --";
			// 
			// lblSensor5
			// 
			this->lblSensor5->AutoSize = true;
			this->lblSensor5->Location = System::Drawing::Point(391, 65);
			this->lblSensor5->Name = L"lblSensor5";
			this->lblSensor5->Size = System::Drawing::Size(74, 16);
			this->lblSensor5->TabIndex = 5;
			this->lblSensor5->Text = L"Sensor 5: --";
			// 
			// lblSensor4
			// 
			this->lblSensor4->AutoSize = true;
			this->lblSensor4->Location = System::Drawing::Point(391, 39);
			this->lblSensor4->Name = L"lblSensor4";
			this->lblSensor4->Size = System::Drawing::Size(74, 16);
			this->lblSensor4->TabIndex = 4;
			this->lblSensor4->Text = L"Sensor 4: --";
			// 
			// lblSensor3
			// 
			this->lblSensor3->AutoSize = true;
			this->lblSensor3->Location = System::Drawing::Point(8, 92);
			this->lblSensor3->Name = L"lblSensor3";
			this->lblSensor3->Size = System::Drawing::Size(74, 16);
			this->lblSensor3->TabIndex = 3;
			this->lblSensor3->Text = L"Sensor 3: --";
			// 
			// lblSensor2
			// 
			this->lblSensor2->AutoSize = true;
			this->lblSensor2->Location = System::Drawing::Point(8, 65);
			this->lblSensor2->Name = L"lblSensor2";
			this->lblSensor2->Size = System::Drawing::Size(74, 16);
			this->lblSensor2->TabIndex = 2;
			this->lblSensor2->Text = L"Sensor 2: --";
			// 
			// lblSensor1
			// 
			this->lblSensor1->AutoSize = true;
			this->lblSensor1->Location = System::Drawing::Point(8, 39);
			this->lblSensor1->Name = L"lblSensor1";
			this->lblSensor1->Size = System::Drawing::Size(74, 16);
			this->lblSensor1->TabIndex = 1;
			this->lblSensor1->Text = L"Sensor 1: --";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 665);
			this->Controls->Add(this->tabCtrlApplication);
			this->Controls->Add(this->statusStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"Controle de estante irrigada";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabComm->ResumeLayout(false);
			this->tabComm->PerformLayout();
			this->gbxEcho->ResumeLayout(false);
			this->gbxEcho->PerformLayout();
			this->gbxSerialConnection->ResumeLayout(false);
			this->gbxNetConnect->ResumeLayout(false);
			this->gbxNetConnect->PerformLayout();
			this->tabCtrlApplication->ResumeLayout(false);
			this->tabConfig->ResumeLayout(false);
			this->gbxServerMode->ResumeLayout(false);
			this->gbxServerMode->PerformLayout();
			this->gbxSensor6->ResumeLayout(false);
			this->gbxSensor6->PerformLayout();
			this->gbxSensor5->ResumeLayout(false);
			this->gbxSensor5->PerformLayout();
			this->gbxSensor4->ResumeLayout(false);
			this->gbxSensor4->PerformLayout();
			this->gbxSensor3->ResumeLayout(false);
			this->gbxSensor3->PerformLayout();
			this->gbxSensor2->ResumeLayout(false);
			this->gbxSensor2->PerformLayout();
			this->gbxSensor1->ResumeLayout(false);
			this->gbxSensor1->PerformLayout();
			this->gbxRTC->ResumeLayout(false);
			this->gbxRTC->PerformLayout();
			this->tabSamples->ResumeLayout(false);
			this->tabSamples->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Module ^device, ^tcpDevice;
			bool requestPowerDownVisualAnswer;

			System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
			{
				loadTxtIfConfigExists(txtIP1);
				loadTxtIfConfigExists(txtIP2);
				loadTxtIfConfigExists(txtIP3);
				loadTxtIfConfigExists(txtIP4);
				loadTxtIfConfigExists(txtPort);

				cmbxControl1Operation->SelectedIndex = 0;
				cmbxControl2Operation->SelectedIndex = 0;
				cmbxControl3Operation->SelectedIndex = 0;
				cmbxControl4Operation->SelectedIndex = 0;
				cmbxControl5Operation->SelectedIndex = 0;
				cmbxControl6Operation->SelectedIndex = 0;

				setInterfaceState();
			}

			System::Void cmboxSerialPorts_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				array<String ^> ^portNames = SerialPort::GetPortNames();

				cmboxSerialPorts->Items->Clear();
				for each(String ^name in portNames)
					cmboxSerialPorts->Items->Add(name);
			}

			System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (btnConnect->Text == "Conectar")
				{
					USBDevice ^virtualComm = gcnew USBDevice((String ^)cmboxSerialPorts->Items[cmboxSerialPorts->SelectedIndex]);
					virtualComm->BaudRate = 115200;
					device = gcnew Module(virtualComm);
					device->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					device->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);
					try
					{
						device->Open();
					}
					catch (UnauthorizedAccessException ^)
					{
						MessageBox::Show("Porta não pode ser aberta", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					catch (ArgumentException ^)
					{
						MessageBox::Show("Nome de porta inválido", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					catch (IOException ^)
					{
						MessageBox::Show("Porta encontra-se em estado inválido", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					catch (InvalidOperationException ^)
					{
						MessageBox::Show("Porta já está aberta", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					if (device->Connected)
					{
						array<unsigned char>^ buffer = gcnew array<unsigned char>(4);

						setInterfaceState();
					}
				}
				else
				{
					device->Close();
					device = nullptr;
					setInterfaceState();
				}
			}

			System::Void btnNetConnect_Click(System::Object^ sender, System::EventArgs^ e)
			{
				if (btnNetConnect->Text == "Conectar")
				{
					TCPIP4Device ^ipPort = getTCPIP4DeviceFromTextboxes(txtIP1, txtIP2, txtIP3, txtIP4, txtPort);
					tcpDevice = gcnew Module(ipPort);
					tcpDevice->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					tcpDevice->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);

					try
					{
						tcpDevice->Open();
					}
					catch (System::SystemException ^e)
					{
						MessageBox::Show(e->Message, "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
					if (tcpDevice->Connected)
					{
						saveTxtToConfig(txtIP1);
						saveTxtToConfig(txtIP2);
						saveTxtToConfig(txtIP3);
						saveTxtToConfig(txtIP4);
						saveTxtToConfig(txtPort);

						setInterfaceState();
					}
				}
				else
				{
					tcpDevice->Close();
					tcpDevice = nullptr;
					setInterfaceState();
				}
			}

			System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e)
			{
				UdpClient^ udpSender;
				IPEndPoint^ eqptEndPoint;
				array<unsigned char>^ tempBuffer = gcnew array<unsigned char>(3);
				array<unsigned char>^ packet;
				bool found = false;

				try
				{
					udpSender = gcnew UdpClient(30000);
					eqptEndPoint = gcnew IPEndPoint(IPAddress::Broadcast, 30000);
					tempBuffer[0] = 'S';
					tempBuffer[1] = 'C';
					tempBuffer[2] = 'H';
					udpSender->EnableBroadcast = true;

					udpSender->Send(tempBuffer, tempBuffer->Length, eqptEndPoint);
				}
				catch (SocketException^)
				{
					MessageBox::Show("Porta já está em uso.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
				Thread::Sleep(500);
				while (udpSender->Available && found == false)
				{
					packet = udpSender->Receive(eqptEndPoint);
					if (packet->Length == 7 && packet[0] == 'S' && packet[1] == 'C' && packet[2] == 'H')
					{
						found = true;
					}
				}
				udpSender->Close();
				
				if (found)
				{
					txtIP1->Text = String::Format("{0}", packet[3]);
					txtIP2->Text = String::Format("{0}", packet[4]);
					txtIP3->Text = String::Format("{0}", packet[5]);
					txtIP4->Text = String::Format("{0}", packet[6]); 
					txtPort->Text = "5000";
					TCPIP4Device^ ipPort = getTCPIP4DeviceFromTextboxes(txtIP1, txtIP2, txtIP3, txtIP4, txtPort);
					tcpDevice = gcnew Module(ipPort);
					tcpDevice->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					tcpDevice->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);

					try
					{
						tcpDevice->Open();
					}
					catch (System::SystemException^ e)
					{
						MessageBox::Show(e->Message, "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
					if (tcpDevice->Connected)
					{
						saveTxtToConfig(txtIP1);
						saveTxtToConfig(txtIP2);
						saveTxtToConfig(txtIP3);
						saveTxtToConfig(txtIP4);
						saveTxtToConfig(txtPort);

						setInterfaceState();
					}
				}
				else
				{
					MessageBox::Show("Nenhum dispositivo de captura de sinais foi encontrado na rede wireless.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}

			void setInterfaceState(void)
			{
				bool usbConnected = (device != nullptr && device->Connected) ? true : false;
				bool tcpConnected = (tcpDevice != nullptr && tcpDevice->Connected) ? true : false;
				bool deviceConnected = (usbConnected || tcpConnected);

				lblEcho->Enabled = deviceConnected;
				txtSendMessage->Enabled = deviceConnected;
				btnSendEcho->Enabled = deviceConnected;
				txtMessages->Enabled = deviceConnected;
				btnTxtClear->Enabled = deviceConnected;
				gbxEcho->Enabled = deviceConnected;
				gbxServerMode->Enabled = deviceConnected;
				gbxRTC->Enabled = deviceConnected;
				gbxSensor1->Enabled = deviceConnected;
				gbxSensor2->Enabled = deviceConnected;
				gbxSensor3->Enabled = deviceConnected;
				gbxSensor4->Enabled = deviceConnected;
				gbxSensor5->Enabled = deviceConnected;
				gbxSensor6->Enabled = deviceConnected;
				btnSaveConfigs->Enabled = deviceConnected;
				btnEnterPowerDown->Enabled = deviceConnected;

				if (usbConnected)
				{
					btnConnect->Text = "Desconectar";
					stLabelConnection->Text = "USB: Conectado";
					cmboxSerialPorts->Enabled = false;
				}
				else
				{
					btnConnect->Text = "Conectar";
					stLabelConnection->Text = "USB: Desconectado";
					cmboxSerialPorts->Enabled = true;
				}

				if (tcpConnected)
				{
					btnNetConnect->Text = "Desconectar";
					stLabelNetConnection->Text = "Net: Conectado";
					btnSearch->Enabled = false;
					txtIP1->Enabled = false;
					txtIP2->Enabled = false;
					txtIP3->Enabled = false;
					txtIP4->Enabled = false;
					txtPort->Enabled = false;
				}
				else
				{
					btnNetConnect->Text = "Conectar";
					stLabelNetConnection->Text = "Net: Desconectado";
					btnSearch->Enabled = true;
					txtIP1->Enabled = true;
					txtIP2->Enabled = true;
					txtIP3->Enabled = true;
					txtIP4->Enabled = true;
					txtPort->Enabled = true;
				}
			}

			TCPIP4Device^ MainForm::getTCPIP4DeviceFromTextboxes(TextBox^ txtBx1, TextBox^ txtBx2, TextBox^ txtBx3, TextBox^ txtBx4, TextBox^ txtPNum)
			{
				TCPIP4Device^ newComm;

				try
				{
					Int32::Parse(txtBx1->Text);
					Int32::Parse(txtBx2->Text);
					Int32::Parse(txtBx3->Text);
					Int32::Parse(txtBx4->Text);
					Int32::Parse(txtPNum->Text);
				}
				catch (...)
				{
					MessageBox::Show("IP ou porta informados são inválidos.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
				newComm = gcnew TCPIP4Device();
				newComm->IP = gcnew String(txtBx1->Text + L"." + txtBx2->Text + L"." + txtBx3->Text + L"." + txtBx4->Text);
				newComm->PortNumber = Convert::ToInt32(txtPNum->Text);

				return(newComm);
			}

			float getSampleValueFromInt(UInt16 value, float refVoltage, float convertionRate)
			{
				float result = safe_cast<float>(Math::Round(((value / 1000.0f) - refVoltage) * convertionRate, 2));
				
				return(result);
			}

			System::Void DisconnectionHandler(Object ^eqp)
			{
				if (btnConnect->InvokeRequired)
				{
					array<Object^>^ myArgArray = { eqp };
					ModuleDisconnection ^action = gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);
					this->Invoke(action, myArgArray);
				}
				else
				{
					btnConnect->Text = "Conectar";
					stLabelConnection->Text = "Desconectado";
					cmboxSerialPorts->Enabled = true;
					lblEcho->Enabled = false;
					txtSendMessage->Enabled = false;
					btnSendEcho->Enabled = false;
					txtMessages->Enabled = false;
				}
			}

			System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			{
				device->Close();
				tcpDevice->Close();
			}

			System::Void btnTxtClear_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				txtMessages->Clear();
			}

			float getFloatFromTxBox(TextBox^ txtBox)
			{
				float value;

				try
				{
					value = Convert::ToSingle(txtBox->Text);
				}
				catch (...)
				{
					value = 0.0f;
				}

				return value;
			}

			void loadNumUpDownIfConfigExists(NumericUpDown^ numUpDown)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[numUpDown->Name] != nullptr)
					numUpDown->Text = System::Configuration::ConfigurationManager::AppSettings[numUpDown->Name];
			}

			void saveNumUpDownToConfig(NumericUpDown^ numUpDown)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(numUpDown->Name);
				config->AppSettings->Settings->Add(numUpDown->Name, numUpDown->Text);
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void loadTxtIfConfigExists(TextBox^ txtBox)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[txtBox->Name] != nullptr)
					txtBox->Text = System::Configuration::ConfigurationManager::AppSettings[txtBox->Name];
			}

			void saveTxtToConfig(TextBox^ txtBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(txtBox->Name);
				config->AppSettings->Settings->Add(txtBox->Name, txtBox->Text);
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void loadChkBoxIfConfigExists(CheckBox^ chkBox)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[chkBox->Name] != nullptr)
					chkBox->Checked = Convert::ToBoolean(System::Configuration::ConfigurationManager::AppSettings[chkBox->Name]);
			}

			void saveChkBoxToConfig(CheckBox^ chkBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(chkBox->Name);
				config->AppSettings->Settings->Add(chkBox->Name, Convert::ToString(chkBox->Checked));
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void loadComboBoxIfConfigExists(ComboBox^ cmbBox, Int32 defaultValue)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name] != nullptr)
					cmbBox->SelectedIndex = Convert::ToInt32(System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name]);
				else
					cmbBox->SelectedIndex = defaultValue;
			}

			void loadComboBoxTextIfConfigExists(ComboBox^ cmbBox)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name] != nullptr)
				{
					String^ text = System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name];
					cmbBox->Items->Add(text);
					cmbBox->SelectedIndex = cmbBox->FindStringExact(text);
				}
				else
					cmbBox->Text = "";
			}

			void saveComboBoxToConfig(ComboBox^ cmbBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(cmbBox->Name);
				config->AppSettings->Settings->Add(cmbBox->Name, Convert::ToString(cmbBox->SelectedIndex));
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void saveComboBoxTextToConfig(ComboBox^ cmbBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(cmbBox->Name);
				config->AppSettings->Settings->Add(cmbBox->Name, Convert::ToString(cmbBox->Text));
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			UInt16 bcdToInt(unsigned char data)
			{
				return ((((data & 0xF0) >> 4) * 10) + (data & 0x0F));
			}

			unsigned char intToBcd(UInt16 data)
			{
				unsigned char value = ((((data & 0x00FF) / 10) << 4) + (data & 0x00FF) % 10);
				return value;
			}

			Module^ getValidDevice(void)
			{
				Module^ priorityDevice = nullptr;

				if (device != nullptr && device->Connected)
					priorityDevice = device;
				if (tcpDevice != nullptr && tcpDevice->Connected)
					priorityDevice = tcpDevice;

				return(priorityDevice);
			}

			System::Void ReceptionHandler(Object^ eqp, array<unsigned char>^ buffer)
			{
				if (txtMessages->InvokeRequired)
				{
					array<Object^>^ myArgArray = { eqp, buffer };
					ModuleReception^ action = gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					this->Invoke(action, myArgArray);
				}
				else
				{
					switch (buffer[0] & COMMAND_MASK)
					{
						case CMD_MESSAGE:
							txtMessages->Text += Encoding::ASCII->GetString(buffer, 1, buffer->Length - 1);
							break;
						case CMD_GET_DATETIME:
							if ((buffer[0] & SOURCE_MASK) == COMMAND_SOURCE_MODULE)
							{
								lblModuleDateTime->Text = String::Format("Data/Hora do módulo: {0:D02}/{1:D02}/{2} {3:D02}:{4:D02}:{5:D02}",
									bcdToInt(buffer[3]), bcdToInt(buffer[4]), 2000 + bcdToInt(buffer[1]),
									bcdToInt(buffer[5]), bcdToInt(buffer[8]), bcdToInt(buffer[7]));
							}
							else if ((buffer[0] & SOURCE_MASK) == COMMAND_SOURCE_ROUTER)
							{
								lblModuleDateTime->Text = String::Format("Data/Hora do roteador: {0:D02}/{1:D02}/{2} {3:D02}:{4:D02}:{5:D02}",
									bcdToInt(buffer[3]), bcdToInt(buffer[4]), 2000 + bcdToInt(buffer[1]),
									bcdToInt(buffer[5]), bcdToInt(buffer[8]), bcdToInt(buffer[7]));
							}
							break;
						case CMD_SET_DATETIME:
							if(buffer[1] == 0x06)
								MessageBox::Show("Data/Hora atualizada.", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);
							break;
						case CMD_SEND_SAMPLES:
							lblLastSampleInstant->Text = String::Format("Última amostra: {0:D02}/{1:D02}/{2} {3:D02}:{4:D02}:{5:D02}",
								bcdToInt(buffer[3]), bcdToInt(buffer[4]), 2000 + bcdToInt(buffer[1]),
								bcdToInt(buffer[5]), bcdToInt(buffer[8]), bcdToInt(buffer[7]));
							lblSensor1->Text = String::Format("Sensor 1: {0} [Válvula {1}]", BitConverter::ToUInt16(buffer, 9), buffer[21] ? "ativa" : "desativa");
							lblSensor2->Text = String::Format("Sensor 2: {0} [Válvula {1}]", BitConverter::ToUInt16(buffer, 11), buffer[22] ? "ativa" : "desativa");
							lblSensor3->Text = String::Format("Sensor 3: {0} [Válvula {1}]", BitConverter::ToUInt16(buffer, 13), buffer[23] ? "ativa" : "desativa");
							lblSensor4->Text = String::Format("Sensor 4: {0} [Válvula {1}]", BitConverter::ToUInt16(buffer, 15), buffer[24] ? "ativa" : "desativa");
							lblSensor5->Text = String::Format("Sensor 5: {0} [Válvula {1}]", BitConverter::ToUInt16(buffer, 17), buffer[25] ? "ativa" : "desativa");
							lblSensor6->Text = String::Format("Sensor 6: {0} [Válvula {1}]", BitConverter::ToUInt16(buffer, 19), buffer[26] ? "ativa" : "desativa");

							break;
						case CMD_GET_CONTROL_CONFIG:
							switch (buffer[1])
							{
								case 0:
									cmbxControl1Operation->SelectedIndex = buffer[2];
									txtMinThreshold1->Text = BitConverter::ToUInt16(buffer, 3).ToString();
									txtMaxThreshold1->Text = BitConverter::ToUInt16(buffer, 5).ToString();
									break;
								case 1:
									cmbxControl2Operation->SelectedIndex = buffer[2];
									txtMinThreshold2->Text = BitConverter::ToUInt16(buffer, 3).ToString();
									txtMaxThreshold2->Text = BitConverter::ToUInt16(buffer, 5).ToString();
									break;
								case 2:
									cmbxControl3Operation->SelectedIndex = buffer[2];
									txtMinThreshold3->Text = BitConverter::ToUInt16(buffer, 3).ToString();
									txtMaxThreshold3->Text = BitConverter::ToUInt16(buffer, 5).ToString();
									break;
								case 3:
									cmbxControl4Operation->SelectedIndex = buffer[2];
									txtMinThreshold4->Text = BitConverter::ToUInt16(buffer, 3).ToString();
									txtMaxThreshold4->Text = BitConverter::ToUInt16(buffer, 5).ToString();
									break;
								case 4:
									cmbxControl5Operation->SelectedIndex = buffer[2];
									txtMinThreshold5->Text = BitConverter::ToUInt16(buffer, 3).ToString();
									txtMaxThreshold5->Text = BitConverter::ToUInt16(buffer, 5).ToString();
									break;
								case 5:
									cmbxControl6Operation->SelectedIndex = buffer[2];
									txtMinThreshold6->Text = BitConverter::ToUInt16(buffer, 3).ToString();
									txtMaxThreshold6->Text = BitConverter::ToUInt16(buffer, 5).ToString();
									break;
								default:
									break;
							}
						case CMD_SET_CONTROL_CONFIG:
							if (buffer[1] == 0x06)
								MessageBox::Show("Configuração atualizada", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);
							break;
						case CMD_SAVE_CONFIG:
							if (buffer[1] == 0x06)
								MessageBox::Show("Configurações salvas!", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);
							else
								MessageBox::Show("Configurações não puderam ser salvas.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
							break;
						case CMD_POWER_DOWN:
							if (requestPowerDownVisualAnswer && buffer[1] == 0x06)
							{
								MessageBox::Show("Módulo operando em modo Power Down.", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);
								requestPowerDownVisualAnswer = false;
							}
							break;
						case CMD_SET_TIMEOUT:
							if (buffer[1] == 0x06)
								MessageBox::Show("Comando de alteração de timeout enviado.", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);
							break;
						default:
							break;
					}
				}
			}

			System::Void btnSendEcho_Click(System::Object^ sender, System::EventArgs^ e)
			{
				Module^ priorityDevice = getValidDevice();

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(txtSendMessage->Text->Length + 6);
					array<unsigned char>^ message = Encoding::ASCII->GetBytes(txtSendMessage->Text);
					int index;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = safe_cast<unsigned char>(txtSendMessage->Text->Length + 3);
					// Comando
					buffer[3] = ((cbxSendToRouter->Checked) ? ROUTER_COMMAND : ENDPOINT_COMMAND) | COMMAND_SOURCE_SOFTWARE | CMD_MESSAGE;
					// Texto para envio
					for (index = 0; index < message->Length; index++)
						buffer[4 + index] = message[index];

					buffer[4 + index++] = '\r';
					buffer[4 + index++] = '\n';

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
			}

			System::Void btnReadDateTime_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				Module^ priorityDevice = getValidDevice();

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(4);

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 1;
					// Comando
					buffer[3] = ENDPOINT_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_GET_DATETIME;
					
					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}
			System::Void btnUpdateDateTime_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				Module^ priorityDevice = getValidDevice();

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(12);
					DateTime horaAtual = DateTime::Now;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 9;
					// Comando
					buffer[3] = ENDPOINT_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_SET_DATETIME;
					buffer[4] = intToBcd(horaAtual.Year - 2000);
					buffer[5] = 0;
					buffer[6] = intToBcd(horaAtual.Day);
					buffer[7] = intToBcd(horaAtual.Month);
					buffer[8] = intToBcd(horaAtual.Hour);
					buffer[9] = safe_cast<unsigned char>(horaAtual.DayOfWeek);
					buffer[10] = intToBcd(horaAtual.Second);
					buffer[11] = intToBcd(horaAtual.Minute);

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}

			void getSensorConfig(uint8_t sensorID)
			{
				Module^ priorityDevice = getValidDevice();

				if (sensorID < 6 && priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(5);
					DateTime horaAtual = DateTime::Now;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 2;
					// Comando
					buffer[3] = ENDPOINT_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_GET_CONTROL_CONFIG;
					buffer[4] = sensorID;

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}
			System::Void btnReadSensor1Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				getSensorConfig(0);
			}
			System::Void btnReadSensor2Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				getSensorConfig(1);
			}
			System::Void btnReadSensor3Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				getSensorConfig(2);
			}
			System::Void btnReadSensor4Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				getSensorConfig(3);
			}
			System::Void btnReadSensor5Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				getSensorConfig(4);
			}
			System::Void btnReadSensor6Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				getSensorConfig(5);
			}

			void setSensorConfig(uint8_t sensorID, ComboBox ^controlOperation, TextBox ^sensorMinThreshold, TextBox ^sensorMaxThreshold)
			{
				Module^ priorityDevice = getValidDevice();

				if (sensorID < 6 && priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(10);
					array<unsigned char>^ tempByteArray;
					DateTime horaAtual = DateTime::Now;
					UInt16 minThreshold, maxThreshold;

					try
					{
						minThreshold = Convert::ToUInt16(sensorMinThreshold->Text);
						maxThreshold = Convert::ToUInt16(sensorMaxThreshold->Text);
					}
					catch (System::FormatException^)
					{
						MessageBox::Show("Os limites devem ser valores numéricos.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 7;
					// Comando
					buffer[3] = ENDPOINT_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_SET_CONTROL_CONFIG;
					buffer[4] = sensorID;
					buffer[5] = controlOperation->SelectedIndex;
					tempByteArray = BitConverter::GetBytes(minThreshold);
					buffer[6] = tempByteArray[0];
					buffer[7] = tempByteArray[1];
					tempByteArray = BitConverter::GetBytes(maxThreshold);
					buffer[8] = tempByteArray[0];
					buffer[9] = tempByteArray[1];

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}

			System::Void btnSendSensor1Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				setSensorConfig(0, cmbxControl1Operation, txtMinThreshold1, txtMaxThreshold1);
			}
			System::Void btnSendSensor2Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				setSensorConfig(1, cmbxControl2Operation, txtMinThreshold2, txtMaxThreshold2);
			}
			System::Void btnSendSensor3Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				setSensorConfig(2, cmbxControl3Operation, txtMinThreshold3, txtMaxThreshold3);
			}
			System::Void btnSendSensor4Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				setSensorConfig(3, cmbxControl4Operation, txtMinThreshold4, txtMaxThreshold4);
			}
			System::Void btnSendSensor5Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				setSensorConfig(4, cmbxControl5Operation, txtMinThreshold5, txtMaxThreshold5);
			}
			System::Void btnSendSensor6Config_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				setSensorConfig(5, cmbxControl6Operation, txtMinThreshold6, txtMaxThreshold6);
			}
			System::Void btnSaveConfigs_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				Module^ priorityDevice = getValidDevice();

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(4);
					DateTime horaAtual = DateTime::Now;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 1;
					// Comando
					buffer[3] = ENDPOINT_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_SAVE_CONFIG;

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}

			void setModuleInPowerDown(void)
			{
				Module^ priorityDevice = getValidDevice();

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(4);
					DateTime horaAtual = DateTime::Now;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 1;
					// Comando
					buffer[3] = ENDPOINT_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_POWER_DOWN;

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}

			System::Void btnEnterPowerDown_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				requestPowerDownVisualAnswer = true;
				setModuleInPowerDown();
			}
			void setPowerDown(uint8_t val)
			{
				Module^ priorityDevice = getValidDevice();

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(5);

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 2;
					// Comando
					buffer[3] = ROUTER_COMMAND | COMMAND_SOURCE_SOFTWARE | CMD_SET_TIMEOUT;
					buffer[4] = val;

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
				else
				{
					MessageBox::Show("Sistema não conectado.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					this->cbxHaltPowerDown->CheckedChanged -= gcnew System::EventHandler(this, &MainForm::cbxHaltPowerDown_CheckedChanged);
					cbxHaltPowerDown->Checked = false;
					this->cbxHaltPowerDown->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxHaltPowerDown_CheckedChanged);
				}
			}
			System::Void cbxHaltPowerDown_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				setPowerDown((cbxHaltPowerDown->Checked) ? 1 : 0);
			}
};
}
