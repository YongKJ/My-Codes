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
	/// Form5 摘要
	/// </summary>
	public ref class Form5 : public System::Windows::Forms::Form
	{
	public:
		Form5(personalFinance theFinance)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			myFinance=new personalFinance;
			*myFinance=theFinance;
			userModifyUI();
			showUser();
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
		void userModifyUI(){
			this->Text = L"用户修改";

			this->textBox1->ReadOnly = true;
			this->textBox2->ReadOnly = false;
			this->textBox3->ReadOnly = false;
			this->textBox3->ReadOnly = false;

			this->button1->Text = L"修改";
			this->button2->Text = L"返回";
		}
		bool judgeTheUser(){
			if(this->textBox1->Text==""||
			   this->textBox2->Text==""||
			   this->textBox3->Text==""||
			   this->textBox4->Text==""){
				return false;
			}
			return true;
		}
		User getTheUser(){
			User user=myFinance->getUser();
			user.ID=changeToDouble(changeTostring(this->textBox1->Text));
			user.Name=changeTostring(this->textBox2->Text);
			user.Password=changeTostring(this->textBox3->Text);
			user.realName=changeTostring(this->textBox4->Text);
			return user;
		}
		void showUser(){
			User user=myFinance->getUser();
			this->textBox1->Text=changeToString(changeTostring(user.ID));
			this->textBox2->Text=changeToString(user.Name);
			this->textBox3->Text=changeToString(user.Password);
			this->textBox4->Text=changeToString(user.realName);
		}
		personalFinance *myFinance;
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form5()
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(36, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"编号：";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(105, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(189, 27);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox2->Location = System::Drawing::Point(105, 89);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(189, 27);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form5::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(36, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"用户名：";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox3->Location = System::Drawing::Point(105, 142);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(193, 27);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form5::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(36, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"密码：";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox4->Location = System::Drawing::Point(105, 206);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(189, 27);
			this->textBox4->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(36, 211);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"姓名：";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(39, 281);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 25);
			this->button1->TabIndex = 8;
			this->button1->Text = L"修改";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form5::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"宋体", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(219, 281);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 25);
			this->button2->TabIndex = 9;
			this->button2->Text = L"返回";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form5::button2_Click);
			// 
			// Form5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 342);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form5";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"用户修改";
			this->Load += gcnew System::EventHandler(this, &Form5::Form5_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form5_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(judgeTheUser()){
					 if(myFinance->userModify(getTheUser())){
						MessageBox::Show("修改成功！","用户修改");
						this->Close();
					 }else{
						MessageBox::Show("用户名已存在！","用户修改");
					 }
				 }else{
					MessageBox::Show("请检查输入的用户信息！","用户修改");
				 }
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
