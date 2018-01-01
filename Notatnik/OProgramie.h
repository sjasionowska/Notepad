#pragma once

namespace Notatnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class OProgramie : public System::Windows::Forms::Form
	{
	public:
		OProgramie(void)
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
		~OProgramie()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OK;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OProgramie::typeid));
			this->OK = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// OK
			// 
			this->OK->BackColor = System::Drawing::SystemColors::Control;
			this->OK->Cursor = System::Windows::Forms::Cursors::Default;
			this->OK->Location = System::Drawing::Point(119, 318);
			this->OK->MinimumSize = System::Drawing::Size(91, 36);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(91, 36);
			this->OK->TabIndex = 0;
			this->OK->Text = L"OK";
			this->OK->UseVisualStyleBackColor = false;
			this->OK->Click += gcnew System::EventHandler(this, &OProgramie::OK_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(300, 300);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// OProgramie
			// 
			this->AcceptButton = this->OK;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(323, 360);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->OK);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(341, 399);
			this->Name = L"OProgramie";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"O programie";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OK_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		OProgramie::Close();
	}
	};
}
