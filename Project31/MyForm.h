#pragma once
#include <time.h>
#include <random>

namespace Project31 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 456);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gr = CreateGraphics();
		srand(time(0));
		Point top(90, 20);
		Point left(50, 70);
		Point right(140, 70);

		gr->DrawLine(Pens::Transparent, top, left);
		gr->DrawLine(Pens::Transparent, top, right);
		gr->DrawLine(Pens::Transparent, right, left);

		top.X += rand() % ClientSize.Width / 2;
		top.Y += rand() % ClientSize.Height / 2;

		left.X += rand() % ClientSize.Width / 2;
		left.Y += rand() % ClientSize.Height / 2;

		right.X += rand() % ClientSize.Width / 2;
		right.Y += rand() % ClientSize.Height / 2;

		int i = rand() % 4;

		// Color Pens
		switch (i)
		{
		case 0:
			gr->DrawLine(Pens::Red, top, left);
			gr->DrawLine(Pens::Red, top, right);
			gr->DrawLine(Pens::Red, right, left);
			break;
		case 1:
			gr->DrawLine(Pens::Blue, top, left);
			gr->DrawLine(Pens::Blue, top, right);
			gr->DrawLine(Pens::Blue, right, left);
			break;
		case 2:
			gr->DrawLine(Pens::Green, top, left);
			gr->DrawLine(Pens::Green, top, right);
			gr->DrawLine(Pens::Green, right, left);
			break;
		default:
			gr->DrawLine(Pens::Black, top, left);
			gr->DrawLine(Pens::Black, top, right);
			gr->DrawLine(Pens::Black, right, left);
		}
		
		
		
	
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		timer1->Enabled = true;
		timer1->Interval = 70;
	}
	};
}