#pragma once

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
	/// Form3 摘要
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(personalFinance theFinance)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			myFinance=new personalFinance;
			*myFinance=theFinance;
			fixedTradeManagementUI();
			myFinance->tradeManagementOperation(1,getTheBankCard(),getTheTrade());
			showTrade();
			updateFlag=0;
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
		string changeTostring(int val){ //int转string
			stringstream ss;
			ss<<val; 
			string aa = ss.str();
			return aa;
		}
		void fixedTradeManagementUI(){
			this->textBox1->ReadOnly = true;
			this->textBox5->ReadOnly = true;

			this->textBox4->ReadOnly = true;
			this->textBox3->ReadOnly = true;

			this->textBox2->ReadOnly = true;

		}
		void looseTradeManagementUI(){
			this->textBox1->ReadOnly = true;
			this->textBox5->ReadOnly = false;

			this->textBox4->ReadOnly = false;
			this->textBox3->ReadOnly = false;

			this->textBox2->ReadOnly = false;

		}
		void showTrade(){
			Trade trade=myFinance->getUsrBankCardTrade();

			this->label2->Text=changeToString(trade.cardID);

			this->textBox1->Text =changeToString(changeTostring(trade.ID));
			this->textBox5->Text =changeToString(trade.dateTime);

			this->textBox4->Text =changeToString(changeTostring(trade.tradeMoney));
			this->textBox3->Text =changeToString(trade.Type);

			this->textBox2->Text =changeToString(trade.About);

			this->label9->Text=changeToString(changeTostring(myFinance->getUsrBankCardTradesSum()));

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
			if(this->textBox5->Text==""||
			   this->textBox4->Text==""||
			   this->textBox3->Text==""||
			   this->textBox2->Text==""||
			   !(this->textBox3->Text=="收入"||
			   this->textBox3->Text=="支出")||
			   !isNum(changeTostring(this->textBox4->Text)))
			   return false;
			return true;
		}
		Trade getTheTrade(){
			Trade trade;

			trade.cardID=changeTostring(this->label2->Text);

			trade.ID=changeToDouble(changeTostring(this->textBox1->Text));
			trade.dateTime=changeTostring(this->textBox5->Text);

			trade.tradeMoney=changeToDouble(changeTostring(this->textBox4->Text));
			trade.Type=changeTostring(this->textBox3->Text);

			trade.About=changeTostring(this->textBox2->Text);

			return trade;
		}
		BankCard getTheBankCard(){
			return myFinance->getUsrBankCard();
		}
		int updateFlag;
	private: System::Windows::Forms::Button^  button6;
	public: 
		personalFinance *myFinance;
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  button5;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(34, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"卡号：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(104, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(34, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"交易号：";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(111, 67);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(150, 27);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form3::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox2->Location = System::Drawing::Point(111, 165);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(415, 27);
			this->textBox2->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(34, 169);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"备注:";
			this->label4->Click += gcnew System::EventHandler(this, &Form3::label4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox3->Location = System::Drawing::Point(376, 116);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 27);
			this->textBox3->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(284, 122);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"交易类型";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox4->Location = System::Drawing::Point(111, 116);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(150, 27);
			this->textBox4->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(34, 120);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"交易额:";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox5->Location = System::Drawing::Point(376, 67);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(150, 27);
			this->textBox5->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(284, 72);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 17);
			this->label7->TabIndex = 10;
			this->label7->Text = L"交易时间：";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label8->Location = System::Drawing::Point(34, 217);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 17);
			this->label8->TabIndex = 13;
			this->label8->Text = L"总共";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label9->Location = System::Drawing::Point(82, 217);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 17);
			this->label9->TabIndex = 12;
			this->label9->Text = L"0";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(35, 257);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 27);
			this->button1->TabIndex = 14;
			this->button1->Text = L"第一条";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(173, 257);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 27);
			this->button2->TabIndex = 15;
			this->button2->Text = L"上一条";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form3::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button3->Location = System::Drawing::Point(451, 257);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 27);
			this->button3->TabIndex = 17;
			this->button3->Text = L"最末条";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form3::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button4->Location = System::Drawing::Point(311, 257);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 27);
			this->button4->TabIndex = 16;
			this->button4->Text = L"下一条";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form3::button4_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label10->Location = System::Drawing::Point(111, 217);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 17);
			this->label10->TabIndex = 18;
			this->label10->Text = L"条记录";
			this->label10->Click += gcnew System::EventHandler(this, &Form3::label10_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button5->Location = System::Drawing::Point(451, 308);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 27);
			this->button5->TabIndex = 19;
			this->button5->Text = L"返回";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form3::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button6->Location = System::Drawing::Point(35, 308);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 27);
			this->button6->TabIndex = 20;
			this->button6->Text = L"修改";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form3::button6_Click_1);
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 363);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"Form3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"交易信息";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			if(myFinance->tradeManagementOperation(2,getTheBankCard(),getTheTrade())){
				//MessageBox::Show("转到上一条成功！","上一条");
				showTrade();
			 }else{
				MessageBox::Show("已到最后一条！","下一条");
			 }
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 if(myFinance->tradeManagementOperation(1,getTheBankCard(),getTheTrade())){
				MessageBox::Show("转到第一条成功！","第一条");
				showTrade();
			 }else{
				MessageBox::Show("转到第一条失败！","第一条");
			 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(myFinance->tradeManagementOperation(3,getTheBankCard(),getTheTrade())){
				//MessageBox::Show("转到上一条成功！","上一条");
				showTrade();
			 }else{
				MessageBox::Show("已到第一条！","上一条");
			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(myFinance->tradeManagementOperation(4,getTheBankCard(),getTheTrade())){
				MessageBox::Show("转到最末条成功！","最末条");
				showTrade();
			 }else{
				MessageBox::Show("转到最末条失败！","最末条");
			 }
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
			 //Application::Exit();
		 }
private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			looseTradeManagementUI();
			if(updateFlag==1){
			if(judgeTheTrade()){
				if(myFinance->tradeManagementOperation(5,getTheBankCard(),getTheTrade())){
					updateFlag=0;
					showTrade();
					fixedTradeManagementUI();
					MessageBox::Show("修改交易信息成功！","修改");
				}else{
					MessageBox::Show("修改交易信息失败！","修改");
				}
			}else{
				MessageBox::Show("请检查交易信息！","修改");
			}
			}else{
				updateFlag=1;
			}
		 }
};
}
