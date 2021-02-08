#pragma once
#include "stdafx.h"
#include "Form2.h"
#include "Form4.h"


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
	/// Form1 ժҪ
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			myFinance=new personalFinance;
		}
		String^ changeToString(string a){
			String^ b=gcnew String(a.c_str());   //stringת��Ϊ�й�String
			return b;
		}
		string changeTostring(String^ a){
			string b = marshal_as<string>(a); //���й�StringתΪstring
			return b;
		}
		double changeToDouble(string a){
			double num=atof(a.c_str());  //stringתΪdouble  ,atoiתΪint
			return num;
		}
		string changeTostring(double val){ //doubleתstring
		char str[256];                    
		sprintf(str, "%lf", val);
		string aa = str;
		return aa;
		}
		User getTheUser(){
			User user;
			user.ID=myFinance->getUsrsSum();
			user.Name=changeTostring(this->textBox1->Text);
			user.Password=changeTostring(this->textBox2->Text);
			user.realName="������";
			return user;
		}
		bool judgeTheUser(){
			if(this->textBox1->Text==""||
			   this->textBox2->Text=="")
			   return false;
			return true;
		}
		personalFinance *myFinance;
	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(142, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(213, 25);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(141, 119);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(214, 25);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(44, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"�û�����";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(44, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"���룺";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(47, 209);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = L"��¼";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"����", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(274, 209);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(81, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"ע��";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(407, 290);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�û���¼";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(judgeTheUser()){
				 if(myFinance->saveUsrNameAndPassword(getTheUser())){
					Form4^ f=gcnew Form4(*myFinance);
					f->Show();
					this->Hide();
				 }else{
					MessageBox::Show("�û��Ѵ��ڣ�","ע��");
				 }
			 }else{
				MessageBox::Show("����������û���Ϣ��","ע��");
			 }
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(judgeTheUser()){
			 if(myFinance->userLogin(getTheUser())){
				MessageBox::Show("��¼�ɹ���","��¼");
				//MessageBox::Show("���Ų����ڻ����벻��ȷ��","����");
				Form2^ f=gcnew Form2(*myFinance);
				//MessageBox::Show("-1");
				f->Show();
				this->Hide();
				//Application::Exit();
			 }else{
				MessageBox::Show("�û������������","��¼");
			 }
			}else{
				MessageBox::Show("����������û���Ϣ��","��¼");
			}
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

