#pragma once
#include "MainController.h"
#include <msclr/marshal.h>

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	MainController mainController;
	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ outputImagePreview;
	private: System::Windows::Forms::RadioButton^ cppLibraryButton;
	private: System::Windows::Forms::RadioButton^ asmLibraryButton;



	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TrackBar^ mixingFactorBar;
	private: System::Windows::Forms::TrackBar^ threadsNumBar;
	private: System::Windows::Forms::Label^ threadsNumLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ mixingFactorLabel;
	private: System::Windows::Forms::Label^ messageBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ elapsedTimeLabel;


	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->outputImagePreview = (gcnew System::Windows::Forms::PictureBox());
			this->cppLibraryButton = (gcnew System::Windows::Forms::RadioButton());
			this->asmLibraryButton = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->mixingFactorBar = (gcnew System::Windows::Forms::TrackBar());
			this->threadsNumBar = (gcnew System::Windows::Forms::TrackBar());
			this->threadsNumLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mixingFactorLabel = (gcnew System::Windows::Forms::Label());
			this->messageBox = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->elapsedTimeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputImagePreview))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mixingFactorBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsNumBar))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(54, 453);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"wybierz zdjêcie nr.1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(220, 453);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"wybierz zdjêcie nr.2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Image Files(*.BMP)|*.BMP";
			// 
			// outputImagePreview
			// 
			this->outputImagePreview->Location = System::Drawing::Point(461, 31);
			this->outputImagePreview->Name = L"outputImagePreview";
			this->outputImagePreview->Size = System::Drawing::Size(499, 355);
			this->outputImagePreview->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->outputImagePreview->TabIndex = 2;
			this->outputImagePreview->TabStop = false;
			// 
			// cppLibraryButton
			// 
			this->cppLibraryButton->AutoSize = true;
			this->cppLibraryButton->Location = System::Drawing::Point(54, 150);
			this->cppLibraryButton->Name = L"cppLibraryButton";
			this->cppLibraryButton->Size = System::Drawing::Size(111, 20);
			this->cppLibraryButton->TabIndex = 4;
			this->cppLibraryButton->TabStop = true;
			this->cppLibraryButton->Text = L"biblioteka c++";
			this->cppLibraryButton->UseVisualStyleBackColor = true;
			// 
			// asmLibraryButton
			// 
			this->asmLibraryButton->AutoSize = true;
			this->asmLibraryButton->Checked = true;
			this->asmLibraryButton->Location = System::Drawing::Point(54, 176);
			this->asmLibraryButton->Name = L"asmLibraryButton";
			this->asmLibraryButton->Size = System::Drawing::Size(116, 20);
			this->asmLibraryButton->TabIndex = 5;
			this->asmLibraryButton->TabStop = true;
			this->asmLibraryButton->Text = L"biblioteka asm";
			this->asmLibraryButton->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(760, 453);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 60);
			this->button3->TabIndex = 6;
			this->button3->Text = L"wykonaj";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainWindow::button3_Click);
			// 
			// mixingFactorBar
			// 
			this->mixingFactorBar->LargeChange = 8;
			this->mixingFactorBar->Location = System::Drawing::Point(483, 392);
			this->mixingFactorBar->Maximum = 255;
			this->mixingFactorBar->Name = L"mixingFactorBar";
			this->mixingFactorBar->Size = System::Drawing::Size(460, 56);
			this->mixingFactorBar->TabIndex = 7;
			this->mixingFactorBar->TickFrequency = 16;
			this->mixingFactorBar->Value = 128;
			this->mixingFactorBar->Scroll += gcnew System::EventHandler(this, &MainWindow::mixingFactorBar_Scroll);
			// 
			// threadsNumBar
			// 
			this->threadsNumBar->LargeChange = 4;
			this->threadsNumBar->Location = System::Drawing::Point(39, 49);
			this->threadsNumBar->Maximum = 64;
			this->threadsNumBar->Minimum = 1;
			this->threadsNumBar->Name = L"threadsNumBar";
			this->threadsNumBar->Size = System::Drawing::Size(355, 56);
			this->threadsNumBar->TabIndex = 8;
			this->threadsNumBar->TickFrequency = 8;
			this->threadsNumBar->Value = 1;
			this->threadsNumBar->Scroll += gcnew System::EventHandler(this, &MainWindow::threadsNumBar_Scroll);
			// 
			// threadsNumLabel
			// 
			this->threadsNumLabel->AutoSize = true;
			this->threadsNumLabel->Location = System::Drawing::Point(217, 108);
			this->threadsNumLabel->Name = L"threadsNumLabel";
			this->threadsNumLabel->Size = System::Drawing::Size(14, 16);
			this->threadsNumLabel->TabIndex = 9;
			this->threadsNumLabel->Text = L"1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(51, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"wybrana iloœæ w¹tków:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(508, 475);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 16);
			this->label2->TabIndex = 11;
			this->label2->Text = L"stopieñ na³o¿enia obrazów:";
			// 
			// mixingFactorLabel
			// 
			this->mixingFactorLabel->AutoSize = true;
			this->mixingFactorLabel->Location = System::Drawing::Point(686, 475);
			this->mixingFactorLabel->Name = L"mixingFactorLabel";
			this->mixingFactorLabel->Size = System::Drawing::Size(33, 16);
			this->mixingFactorLabel->TabIndex = 12;
			this->mixingFactorLabel->Text = L"50%";
			// 
			// messageBox
			// 
			this->messageBox->AutoSize = true;
			this->messageBox->ForeColor = System::Drawing::Color::Red;
			this->messageBox->Location = System::Drawing::Point(60, 370);
			this->messageBox->Name = L"messageBox";
			this->messageBox->Size = System::Drawing::Size(0, 16);
			this->messageBox->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(508, 506);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 16);
			this->label3->TabIndex = 14;
			this->label3->Text = L"czas obliczeñ:";
			// 
			// elapsedTimeLabel
			// 
			this->elapsedTimeLabel->AutoSize = true;
			this->elapsedTimeLabel->Location = System::Drawing::Point(605, 506);
			this->elapsedTimeLabel->Name = L"elapsedTimeLabel";
			this->elapsedTimeLabel->Size = System::Drawing::Size(35, 16);
			this->elapsedTimeLabel->TabIndex = 15;
			this->elapsedTimeLabel->Text = L"0 ms";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 553);
			this->Controls->Add(this->elapsedTimeLabel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->messageBox);
			this->Controls->Add(this->mixingFactorLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->threadsNumLabel);
			this->Controls->Add(this->threadsNumBar);
			this->Controls->Add(this->mixingFactorBar);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->asmLibraryButton);
			this->Controls->Add(this->cppLibraryButton);
			this->Controls->Add(this->outputImagePreview);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Location = System::Drawing::Point(743, 406);
			this->Name = L"MainWindow";
			this->Text = L"Image Mixer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputImagePreview))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mixingFactorBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsNumBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			msclr::interop::marshal_context ctx;
			mainController.loadFileA(ctx.marshal_as<const char*>(openFileDialog1->FileName));
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			msclr::interop::marshal_context ctx;
			mainController.loadFileB(ctx.marshal_as<const char*>(openFileDialog1->FileName));
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (validateData())
		{
			if (cppLibraryButton->Checked)
			{
				mainController.loadLibrary(MainController::CPP);
			}
			else
			{
				mainController.loadLibrary(MainController::ASM);
			}
			
			float elapsedTime = mainController.mixPixels(mixingFactorBar->Value);

			outputImagePreview->ImageLocation = "tmp.bmp";
			elapsedTimeLabel->Text = elapsedTime.ToString() + " ms";
		}
	}
	private: System::Void threadsNumBar_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		int barValue = threadsNumBar->Value;
		mainController.setThreads(barValue);
		threadsNumLabel->Text = barValue.ToString();
	}

	private: System::Void mixingFactorBar_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		int mixingFactor = mixingFactorBar->Value * 100 / 256;
		mixingFactorLabel->Text = mixingFactor.ToString() + "%";
	}
	private: bool validateData()
	{
		if (!mainController.validateImageLoaded())
		{
			messageBox->Text = "Zdjêcia nie zosta³y za³adowane poprawnie";
			return false;
		}
		if (!mainController.validateImageSize())
		{
			messageBox->Text = "Zdjêcia musz¹ mieæ ten sam rozmiar";
			return false;
		}

		messageBox->Text = String::Empty;
		return true;
	}
};
}
