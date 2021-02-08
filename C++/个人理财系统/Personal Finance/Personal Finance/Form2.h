#pragma once
#include "stdafx.h"
#include "Form3.h"
#include "Form5.h"

namespace PersonalFinance {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;

	/// <summary>
	/// Form2 摘要
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(personalFinance theFinance) 
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			findUsrBankCardUI();
			myFinance=new personalFinance;
			*myFinance=theFinance;
			showUser();
			flag=0;
		}
		String^ changeToString(string a){
			String^ b=gcnew String(a.c_str());   //string转换为托管String
			return b;
		}
		string changeTostring(String^ a){
			string b = marshal_as<string>(a); //将托管String转为string
			return b;
		}
		double changeToDouble(string a){
			double num=atof(a.c_str());  //string转为double  ,atoi转为int
			return num;
		}
		string changeTostring(double val){ //double转string
		char str[256];                    
		sprintf(str, "%lf", val);
		string aa = str;
		return aa;
		}
		void findUsrBankCardUI(){//无银行卡模式
			this->button9->Enabled = true;
			this->button7->Enabled = true;
			this->button8->Enabled = true;

			this->textBox1->ReadOnly = false;
			this->textBox1->Text ="";
			this->textBox3->ReadOnly = false;
			this->textBox3->Text ="";

			this->textBox6->ReadOnly = true;
			this->textBox6->Text ="";

			this->label6->Enabled = false;
			this->radioButton1->Enabled = false;
			this->radioButton2->Enabled = false;

			this->label2->Enabled = false;
			this->textBox2->ReadOnly = true;
			this->textBox2->Text ="";

			this->label4->Enabled = false;
			this->textBox4->ReadOnly = true;
			this->textBox4->Text ="";

			this->textBox5->ReadOnly = true;
			this->textBox5->Text ="";

			this->button1->Enabled = true;
			this->button4->Enabled = false;
			this->button4->Text = L"确定";
			this->button6->Enabled = false;
			this->button2->Enabled = false;

		}
		void addUsrBankCardUI(){//添加银行卡模式
			this->button9->Enabled = false;
			this->button7->Enabled = false;
			this->button8->Enabled = false;

			this->textBox1->ReadOnly = false;
			this->textBox3->ReadOnly = false;

			this->textBox6->ReadOnly = false;

			this->label6->Enabled = false;
			this->radioButton1->Enabled = false;
			this->radioButton2->Enabled = false;

			this->label2->Enabled = false;
			this->textBox2->ReadOnly = true;

			this->label4->Enabled = false;
			this->textBox4->ReadOnly = true;

			this->textBox5->ReadOnly = false;

			this->button1->Enabled = true;
			this->button4->Enabled = true;
			this->button4->Text = L"确定";
			this->button6->Enabled = false;
			this->button2->Enabled = false;
			
		}
		void changeUsrBankCardUI(){//修改卡模式
			this->button9->Enabled = false;
			this->button7->Enabled = false;
			this->button8->Enabled = false;

			this->textBox1->ReadOnly = true;
			this->textBox3->ReadOnly = false;

			this->textBox6->ReadOnly = false;

			this->label6->Enabled = false;
			this->radioButton1->Enabled = false;
			this->radioButton2->Enabled = false;

			this->label2->Enabled = false;
			this->textBox2->ReadOnly = true;

			this->label4->Enabled = false;
			this->textBox4->ReadOnly = true;

			this->textBox5->ReadOnly = true;

			this->button1->Enabled = false;
			this->button4->Enabled = true;
			this->button4->Text = L"确定";
			this->button6->Enabled = true;
			this->button2->Enabled = false;
			
		}
		void enterBankCardTradeUI(){//交易模式
			this->button7->Enabled = false;
			this->button8->Enabled = true;

			this->textBox1->ReadOnly = true;
			this->textBox3->ReadOnly = true;

			this->textBox6->ReadOnly = true;

			this->label6->Enabled = true;
			this->radioButton1->Enabled = true;
			this->radioButton2->Enabled = true;

			this->label2->Enabled = true;
			this->textBox2->ReadOnly = false;

			this->label4->Enabled = true;
			this->textBox4->ReadOnly = false;

			this->textBox5->ReadOnly = true;

			this->button1->Enabled = false;
			this->button4->Enabled = true;
			this->button4->Text = L"交易";
			this->button6->Enabled = true;
			this->button2->Enabled = true;
			
		}
		string getSystemTime(){//获取当前系统时间
			time_t timep; 
			time (&timep);
			char tmp[64];
			strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
			return tmp;
		}
		BankCard getTheBankCard(){//获取文本框中的银行卡信息
			User usr=myFinance->getUser();
			BankCard bankCard;
			bankCard.ID=changeTostring(this->textBox1->Text);
			bankCard.Password=changeTostring(this->textBox3->Text);
			bankCard.userID=usr.ID;
			bankCard.bankName=changeTostring(this->textBox6->Text);
			bankCard.Balance=changeToDouble(changeTostring(this->textBox5->Text));
			return bankCard;
		}
		bool judgeTheBankCard(){
			if(this->textBox1->Text==""||
			   this->textBox3->Text==""||
			   this->textBox6->Text==""||
			   this->textBox5->Text==""||
			   !isNum(changeTostring(this->textBox5->Text)))
			   return false;
			return true;
		}
		bool isNum(string str){
		 stringstream sin(str);
		 double d;
		 char c;
		 if(!(sin >> d)){
			return false;
		 }
		 if (sin >> c){
			return false;
		 }
		 return true;
		} 
		bool judgeTheTrade(){
			if(this->textBox2->Text==""||this->textBox4->Text==""||
				(this->radioButton1->Checked==false&&
			     this->radioButton2->Checked==false)||
				(this->radioButton1->Checked==true&&
			     this->radioButton2->Checked==true)||
				 !isNum(changeTostring(this->textBox2->Text)))
				return false;
			return true;
		}
		void showUser(){
			User user=myFinance->getUser();
			//MessageBox::Show(changeToString(user.realName));
			this->label9->Text =changeToString(user.realName);
		}
		void showBankCard(){
			if(flag!=0){
			BankCard bankCard=myFinance->getUsrBankCard();
			this->textBox1->Text=changeToString(bankCard.ID);
			this->textBox3->Text=changeToString(bankCard.Password);
			this->textBox6->Text=changeToString(bankCard.bankName);
			this->textBox5->Text=changeToString(changeTostring(bankCard.Balance));
			}
			// MessageBox::Show(changeToString(bankCard.bankName),"银行名称");

		}
		void showBankCardTrade(){
			Trade trade=myFinance->getUsrBankCardTrade();
			if(trade.Type=="收入"){
				this->radioButton1->Checked = true;
				this->radioButton2->Checked = false;
			}else{
				this->radioButton1->Checked = false;
				this->radioButton2->Checked = true;
			}
			this->textBox2->Text=changeToString(changeTostring(trade.tradeMoney));
			this->textBox4->Text=changeToString(trade.About);
		}
		Trade getTheTrade(){//获取文本框中的交易信息
			BankCard bankCard=myFinance->getUsrBankCard();
			Trade trade;
			trade.ID=(int(myFinance->getUsrBankCardTradesSum())+1);
			trade.cardID=bankCard.ID;
			trade.tradeMoney=changeToDouble(changeTostring(this->textBox2->Text));
			trade.dateTime=getSystemTime();
			trade.Type=(this->radioButton1->Checked == true)?"收入":"支出";
			trade.About=changeTostring(this->textBox4->Text);
			return trade;

		}
		int flag;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Button^  button9;
public: 
	personalFinance *myFinance;
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label7;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(29, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"卡号：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(132, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(135, 25);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form2::textBox1_TextChanged_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(132, 258);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(135, 25);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form2::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(29, 261);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"交易金额：";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(132, 122);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(135, 25);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(29, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"密码：";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(132, 309);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(135, 25);
			this->textBox4->TabIndex = 7;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form2::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(29, 313);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"交易备注：";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(132, 357);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(135, 25);
			this->textBox5->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(29, 361);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"卡内余额：";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(31, 412);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 25);
			this->button1->TabIndex = 10;
			this->button1->Text = L"添加卡";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"宋体", 9.07563F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(31, 460);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 25);
			this->button2->TabIndex = 11;
			this->button2->Text = L"交易管理";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button3->Location = System::Drawing::Point(165, 460);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 25);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button4->Location = System::Drawing::Point(165, 412);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 25);
			this->button4->TabIndex = 12;
			this->button4->Text = L"确定";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button5->Location = System::Drawing::Point(294, 460);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 25);
			this->button5->TabIndex = 15;
			this->button5->Text = L"退出";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form2::button5_Click_1);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button6->Location = System::Drawing::Point(294, 412);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 25);
			this->button6->TabIndex = 14;
			this->button6->Text = L"修改卡";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form2::button6_Click_1);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button7->Location = System::Drawing::Point(294, 73);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 25);
			this->button7->TabIndex = 16;
			this->button7->Text = L"查找";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form2::button7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(29, 218);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 17);
			this->label6->TabIndex = 17;
			this->label6->Text = L"交易类型：";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Enabled = false;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->radioButton1->Location = System::Drawing::Point(146, 215);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(60, 21);
			this->radioButton1->TabIndex = 20;
			this->radioButton1->Text = L"收入";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form2::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->radioButton2->Location = System::Drawing::Point(265, 214);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 21);
			this->radioButton2->TabIndex = 21;
			this->radioButton2->Text = L"支出";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(132, 170);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(135, 25);
			this->textBox6->TabIndex = 23;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Form2::textBox6_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(28, 174);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(110, 17);
			this->label7->TabIndex = 22;
			this->label7->Text = L"银行卡名称：";
			this->label7->Click += gcnew System::EventHandler(this, &Form2::label7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button8->Location = System::Drawing::Point(294, 125);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 25);
			this->button8->TabIndex = 24;
			this->button8->Text = L"刷新";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form2::button8_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(29, 28);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(93, 17);
			this->label8->TabIndex = 25;
			this->label8->Text = L"当前用户：";
			this->label8->Click += gcnew System::EventHandler(this, &Form2::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label9->Location = System::Drawing::Point(129, 28);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(42, 17);
			this->label9->TabIndex = 26;
			this->label9->Text = L"张三";
			this->label9->Click += gcnew System::EventHandler(this, &Form2::label9_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button9->Location = System::Drawing::Point(250, 23);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(120, 25);
			this->button9->TabIndex = 27;
			this->button9->Text = L"修改用户信息";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form2::button9_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 512);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"个人理财系统";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 flag=0;
				 findUsrBankCardUI();
			 }
private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(flag==1){
				 if(judgeTheBankCard()){
					if(myFinance->mainUIOperation(1,getTheBankCard(),getTheTrade())){
						flag=2;
						enterBankCardTradeUI();
						MessageBox::Show("添加银行卡成功！","添加银行卡");
					}else{
						MessageBox::Show("银行卡已存在！","添加银行卡");
					}
				 }else{
					MessageBox::Show("请检查输入的卡号信息！","添加银行卡");
				 }
				
			 }else if(flag==2){
				 if(judgeTheTrade()){
					 if(myFinance->mainUIOperation(4,getTheBankCard(),getTheTrade())){
						showBankCard();
						MessageBox::Show("添加交易成功！","添加交易");
					 }else{
						MessageBox::Show("余额不足，添加交易失败！","添加交易");
					 }
				 }else{
					MessageBox::Show("请检查输入的交易信息！","添加交易");
				 }
			 }else if(flag==3)	{
				if(myFinance->mainUIOperation(3,getTheBankCard(),getTheTrade())){
					flag=2;
					showBankCard();
					enterBankCardTradeUI();
					MessageBox::Show("修改银行卡信息成功！","修改银行卡");
			    }else{
					flag=2;
					enterBankCardTradeUI();
					MessageBox::Show("修改银行卡信息失败！","修改银行卡");
				}
			 }
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBox1->Text!=""||this->textBox3->Text!=""){
				if(myFinance->mainUIOperation(2,getTheBankCard(),getTheTrade())){
					flag=2;
					showBankCard();
					enterBankCardTradeUI();
				}else{
					MessageBox::Show("卡号不存在或密码不正确！","查找银行卡");
				}
			 }else{
				MessageBox::Show("请检查输入的卡号信息！","查找银行卡");
			 }
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				flag=1;
				addUsrBankCardUI();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 flag=3;
			 changeUsrBankCardUI();
			 
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(myFinance->getUsrBankCardTradesSum()!=0){
				Form3^ f=gcnew Form3(*myFinance);
				f->ShowDialog();
			 }else{
				MessageBox::Show("交易记录为空！","交易管理");
			 }
        }
private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
			 Application::Exit();
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 myFinance->updateInformation();
			 showBankCard();
			 showUser();
			 //if(judgeTheTrade())
			// showBankCardTrade();
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			Form5^ f=gcnew Form5(*myFinance);
			f->ShowDialog();							 
		 }
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
