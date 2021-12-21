#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#using <System.dll>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <csignal>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <msclr\marshal_cppstd.h>
namespace Project15 {

	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label12;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(191, 433);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(254, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Запустить рендер";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->groupBox1->Location = System::Drawing::Point(10, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(435, 201);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Конфигурация";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F));
			this->label13->Location = System::Drawing::Point(189, 123);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(184, 14);
			this->label13->TabIndex = 9;
			this->label13->Text = L"Существенно влияет на производительность!\r\nВключает просчет отражений лучей от по"
				L"верхностей";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(168, 123);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->label12->Location = System::Drawing::Point(2, 120);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(146, 18);
			this->label12->TabIndex = 7;
			this->label12->Text = L"Трассировка лучей:";
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 3;
			this->trackBar1->Location = System::Drawing::Point(162, 65);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(211, 45);
			this->trackBar1->TabIndex = 6;
			this->trackBar1->Value = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F));
			this->label5->Location = System::Drawing::Point(3, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 21);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Влияет на производительность!\r\nИскуственно изменяет\r\nскэйлинг рендера\r\n";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->label4->Location = System::Drawing::Point(2, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 18);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Множитель рендера:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->label3->Location = System::Drawing::Point(263, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(15, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"х";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(284, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(89, 26);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"30";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(168, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(89, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"130";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->label2->Location = System::Drawing::Point(2, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 18);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Разрешение консоли:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->pictureBox1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->groupBox2->Location = System::Drawing::Point(9, 219);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(435, 208);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Монитор";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->label6->Location = System::Drawing::Point(237, 25);
			this->label6->Name = L"label6";
			this->label6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 13;
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F));
			this->label9->Location = System::Drawing::Point(-2, 25);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 12);
			this->label9->TabIndex = 12;
			this->label9->Text = L"280 ms";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F));
			this->label10->Location = System::Drawing::Point(-3, 114);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 12);
			this->label10->TabIndex = 11;
			this->label10->Text = L"100 ms";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F));
			this->label11->Location = System::Drawing::Point(-2, 56);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(35, 12);
			this->label11->TabIndex = 10;
			this->label11->Text = L"210 ms";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F));
			this->label7->Location = System::Drawing::Point(-2, 86);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 12);
			this->label7->TabIndex = 9;
			this->label7->Text = L"160 ms";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F));
			this->label8->Location = System::Drawing::Point(2, 138);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 12);
			this->label8->TabIndex = 8;
			this->label8->Text = L"40 ms";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F));
			this->label1->Location = System::Drawing::Point(6, 159);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 12);
			this->label1->TabIndex = 6;
			this->label1->Text = L"0 ms";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->button3->Location = System::Drawing::Point(315, 25);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(114, 34);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Вывести данные";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(16, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(293, 146);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(9, 434);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(81, 33);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(457, 479);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public: int unit = 5; //шаг в пискелах
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int rayTracingValue, renderScale = this->trackBar1->Value + 1;
		bool rayTracing = this->checkBox1->Checked;
		if (rayTracing)
			rayTracingValue = 5;
		else
			rayTracingValue = 1;
		System::String^ clrString = (textBox1->Text);
		std::string width = marshal_as <std::string>(clrString);
		clrString = (textBox2->Text);
		std::string height = marshal_as <std::string>(clrString);

		std::ofstream erase("config.txt", std::ios::out);
		erase.close();
		std::ofstream out("config.txt", std::ios::app);
		if (out.is_open())
		{
			out << width << endl;
			out << height << endl;
			out << renderScale << endl;
			out << rayTracingValue << endl;
		}

		system("3DEngine.exe");
	}	   
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(1);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		string tmp, str;
		double average = 0;
		int n = 0, i = 0;
		int dstr;
		double x = 1;
		ifstream fin("log.txt"); // открыли файл для чтения

		int pW = pictureBox1->Width, pH = pictureBox1->Height;
		Bitmap^ img = gcnew Bitmap(pW, pH);
		//создаем поверхность для рисования (изображение) с размером элемента управления PictureBox
		Graphics^ g = Graphics::FromImage(img); //создаем устройство для рисования на поверхности
		//рисуем сетку:
		//for (int i = 0; i < pW; i += unit) g->DrawLine(Pens::Blue, i, 0, i, pH);
		//for (int i = 0; i < pH; i += unit)  g->DrawLine(Pens::Blue, 0, i, pW, i);
		//находим середину и рисуем линии осей:
		int mX = int(pW / 2 - pW / 2 % unit - 125);
		int mY = int(pH / 2 - pH / 2 % unit + 75);
		g->DrawLine(Pens::Red, mX, 0, mX, pH);
		g->DrawLine(Pens::Red, 0, mY, pW, mY);
		g->ScaleTransform(1, -1); //переворачиваем ось Y для удобства восприятия
		g->TranslateTransform((float)mX, -(float)mY); //смещаем нулевую координату на пересечение осей
		//рисуем график:
		System::Collections::Generic::List<PointF>^ Points =
			gcnew System::Collections::Generic::List<PointF>(); //коллекция точек графика

		if (fin.is_open())
		{
			while (getline(fin, tmp)) {
				str = tmp.substr(12);
				n = str.find("ms");
				str = str.substr(0, n - 1);

				dstr = stoi(str);
				if (i < 100)
				{
					average += dstr;
				}
				else {
					i = 99;
				}
				Points->Add(PointF(x * unit, dstr / 10 * unit));
				x += 0.25;
				i++;
			}
			average = average / i;
			average = 1000 / average;
			this->label6->Text = System::Int32(average).ToString() + " fps";
		}
		else {

		}

		g->DrawLines(Pens::Green, Points->ToArray()); //рисование линий графика
		delete g; //освобождение ресурсов устройства рисования
		this->pictureBox1->Image = img; //присвоение и отображение изображения в PictureBox
	}
};
}
