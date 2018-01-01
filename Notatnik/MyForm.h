#include "OProgramie.h"
#include <iostream>
#include <algorithm>

using namespace System::Diagnostics;


#pragma once

namespace Notatnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	//public ref class OpenFileDialog sealed : FileDialog
	//{
	//	OpenFileDialog::OpenFileDialog();
	//};

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  wytnijCtrlXToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kopiujCtrlCToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  wklejCtrlVToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  formatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zawijanieWierszyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zmianaCzcionkiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pomocToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  informacjeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oProgramieToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  socialMediaToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  tresc;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: String^ nazwapliku = gcnew String("");
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: bool TextChanged = false;

			 //TODO: SetFontColor()
/*	protected: void SetFontColor() 
	{
		if (TextChanged == false)
		{
			tresc->ForeColor.Chocolate;
		}
	}
		*/	 

	protected: virtual void OnClosing(CancelEventArgs^ e) override
	{
		if (TextChanged == false)
		{
			
		}
		else
		{
			// wiadomoœæ, która siê poka¿e; nazwa pliku znana (plik by³ zapisywany 
			// / otwierany wczeœniej) b¹dŸ domyœlna
			String^ message = "Czy zapisaæ zmiany w pliku " + nazwapliku + " przed zakoñczeniem?";
			// "nazwa" okna dialogowego
			String^ caption = "Wa¿ne pytanie";
			// wybieramy jakie chcemy przyciski w oknie z zapytaniem - tak, nie, anuluj
			MessageBoxButtons buttons = MessageBoxButtons::YesNoCancel;
			// obiekt który ma przechowaæ odpowiedŸ
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(message, caption, buttons, MessageBoxIcon::Warning);

			//jeœli wybierzemy Yes
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				// próbujemy zapisaæ plik
				try
				{
					// jeœli nazwa pliku jest pusta, czyli plik nie by³ zapisywany 
					//ani nie pochodzi z otwarcia
					if (this->nazwapliku == "")
					{
						// miejsce, które otworzy siê w oknie dialogowym zapisu
						saveFileDialog1->InitialDirectory = "d:\\";
						// mo¿liwe formaty pliku
						saveFileDialog1->Filter = "Plik tekstowy (txt) (*.txt)|*.txt| Dowolny plik (*.*) | *.*";
						// domyœlna nazwa zapisywanego pliku
						saveFileDialog1->FileName = "Nazwa";

						// wybraliœmy ok, plik siê zapisuje
						// przy pomocy Writera - obiektu, który bêdzie "pisa³" w pliku
						if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
						{
							try
							{
								this->nazwapliku = saveFileDialog1->FileName;
								System::IO::StreamWriter ^ writer = gcnew
									System::IO::StreamWriter(saveFileDialog1->FileName);
								// tresc - nazwa naszego Textboxa
								writer->Write(tresc->Text);
								writer->Close();
								TextChanged = false;
							}

							// wy³apuje ewentualne b³êdy
							catch (Exception ^ ex)
							{
								MessageBox::Show(ex->Message);
								MessageBox::Show("Zapis zakoñczy³ siê niepowodzeniem.");
							}
						}
					}

					// jeœli nazwa pliku jest ju¿ znana program nadpisuje treœæ tego pliku
					else
					{
						System::IO::StreamWriter ^ writer = gcnew
							System::IO::StreamWriter(this->nazwapliku);
						writer->Write(tresc->Text);
						writer->Close();
						TextChanged = false;
					}

				}
				catch (Exception ^ ex)
				{
					MessageBox::Show(ex->Message);
					MessageBox::Show("Zapis zakoñczy³ siê niepowodzeniem.");
				};

			}


			// wybieramy nie
			if (result == System::Windows::Forms::DialogResult::No)
			{
				// program zamyka siê bez zapisywania 
			}

			//wybieramy anuluj
			if (result == System::Windows::Forms::DialogResult::Cancel)
			{
				// rezygnujemy z robienia czegokolwiek i wracamy do naszego pliku tekstowego
				e->Cancel = true;
			}
		}

	}
 
			 
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wytnijCtrlXToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kopiujCtrlCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wklejCtrlVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zawijanieWierszyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zmianaCzcionkiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pomocToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informacjeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oProgramieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->socialMediaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tresc = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->formatToolStripMenuItem, this->pomocToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(619, 41);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->toolStripMenuItem1, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripMenuItem2,
					this->closeToolStripMenuItem
			});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->fileToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fileToolStripMenuItem.Image")));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(41, 37);
			this->fileToolStripMenuItem->Text = L"&Plik";
			this->fileToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->newToolStripMenuItem->Text = L"&Nowy    Ctrl+N";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->openToolStripMenuItem->Text = L"&Otwórz";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(171, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->saveToolStripMenuItem->Text = L"Zapisz    Ctrl + s";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->saveAsToolStripMenuItem->Text = L"Zapisz j&ako...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(171, 6);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->closeToolStripMenuItem->Text = L"Zam&knij";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closeToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->wytnijCtrlXToolStripMenuItem,
					this->kopiujCtrlCToolStripMenuItem, this->wklejCtrlVToolStripMenuItem
			});
			this->editToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->editToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editToolStripMenuItem.Image")));
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(58, 37);
			this->editToolStripMenuItem->Text = L"&Edycja";
			this->editToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// wytnijCtrlXToolStripMenuItem
			// 
			this->wytnijCtrlXToolStripMenuItem->Name = L"wytnijCtrlXToolStripMenuItem";
			this->wytnijCtrlXToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->wytnijCtrlXToolStripMenuItem->Text = L"Wytnij    Ctrl + x";
			this->wytnijCtrlXToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::wytnijCtrlXToolStripMenuItem_Click);
			// 
			// kopiujCtrlCToolStripMenuItem
			// 
			this->kopiujCtrlCToolStripMenuItem->Name = L"kopiujCtrlCToolStripMenuItem";
			this->kopiujCtrlCToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->kopiujCtrlCToolStripMenuItem->Text = L"Kopiuj    Ctrl + c";
			this->kopiujCtrlCToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::kopiujCtrlCToolStripMenuItem_Click);
			// 
			// wklejCtrlVToolStripMenuItem
			// 
			this->wklejCtrlVToolStripMenuItem->Name = L"wklejCtrlVToolStripMenuItem";
			this->wklejCtrlVToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->wklejCtrlVToolStripMenuItem->Text = L"Wklej     Ctrl + v";
			this->wklejCtrlVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::wklejCtrlVToolStripMenuItem_Click);
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->zawijanieWierszyToolStripMenuItem,
					this->zmianaCzcionkiToolStripMenuItem
			});
			this->formatToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->formatToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"formatToolStripMenuItem.Image")));
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->Size = System::Drawing::Size(64, 37);
			this->formatToolStripMenuItem->Text = L"&Format";
			this->formatToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// zawijanieWierszyToolStripMenuItem
			// 
			this->zawijanieWierszyToolStripMenuItem->Checked = true;
			this->zawijanieWierszyToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->zawijanieWierszyToolStripMenuItem->Name = L"zawijanieWierszyToolStripMenuItem";
			this->zawijanieWierszyToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->zawijanieWierszyToolStripMenuItem->Text = L"Zawijanie wierszy";
			this->zawijanieWierszyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zawijanieWierszyToolStripMenuItem_Click);
			// 
			// zmianaCzcionkiToolStripMenuItem
			// 
			this->zmianaCzcionkiToolStripMenuItem->Name = L"zmianaCzcionkiToolStripMenuItem";
			this->zmianaCzcionkiToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->zmianaCzcionkiToolStripMenuItem->Text = L"Zmiana czcionki";
			this->zmianaCzcionkiToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zmianaCzcionkiToolStripMenuItem_Click);
			// 
			// pomocToolStripMenuItem
			// 
			this->pomocToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->informacjeToolStripMenuItem });
			this->pomocToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->pomocToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pomocToolStripMenuItem.Image")));
			this->pomocToolStripMenuItem->Name = L"pomocToolStripMenuItem";
			this->pomocToolStripMenuItem->Size = System::Drawing::Size(62, 37);
			this->pomocToolStripMenuItem->Text = L"Po&moc";
			this->pomocToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// informacjeToolStripMenuItem
			// 
			this->informacjeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->oProgramieToolStripMenuItem,
					this->socialMediaToolStripMenuItem
			});
			this->informacjeToolStripMenuItem->Name = L"informacjeToolStripMenuItem";
			this->informacjeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->informacjeToolStripMenuItem->Text = L"Informacje";
			// 
			// oProgramieToolStripMenuItem
			// 
			this->oProgramieToolStripMenuItem->Name = L"oProgramieToolStripMenuItem";
			this->oProgramieToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->oProgramieToolStripMenuItem->Text = L"O programie";
			this->oProgramieToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::oProgramieToolStripMenuItem_Click);
			// 
			// socialMediaToolStripMenuItem
			// 
			this->socialMediaToolStripMenuItem->Name = L"socialMediaToolStripMenuItem";
			this->socialMediaToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->socialMediaToolStripMenuItem->Text = L"Zapraszam na Youtube";
			this->socialMediaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::socialMediaToolStripMenuItem_Click);
			// 
			// tresc
			// 
			this->tresc->BackColor = System::Drawing::Color::SeaShell;
			this->tresc->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tresc->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tresc->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tresc->ForeColor = System::Drawing::Color::Black;
			this->tresc->Location = System::Drawing::Point(0, 41);
			this->tresc->Name = L"tresc";
			this->tresc->Size = System::Drawing::Size(619, 247);
			this->tresc->TabIndex = 1;
			this->tresc->Text = L"";
			this->tresc->TextChanged += gcnew System::EventHandler(this, &MyForm::tresc_TextChanged);
			this->tresc->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::tresc_KeyDown);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// fontDialog1
			// 
			this->fontDialog1->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->fontDialog1->ShowApply = true;
			this->fontDialog1->ShowColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(619, 288);
			this->Controls->Add(this->tresc);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Notatnik";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		////// MENU PLIK ///
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		openFileDialog1->InitialDirectory = "d:\\";
		openFileDialog1->Filter = "Pliki tekstowe (txt) (*.txt)|*.txt|Wszystkie dokumenty (*.*)|*.*";
		openFileDialog1->FileName = "Nazwa";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try 
			{
				System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
				nazwapliku=openFileDialog1->FileName; 
				tresc->Text = sr->ReadToEnd();
				sr->Close();
				TextChanged = false;
			}

			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message);
				MessageBox::Show("B³¹d otwarcia pliku. Upewnij siê, ¿e plik istnieje.");
			}
		}
	}
	private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		saveFileDialog1->InitialDirectory = "d:\\";
		saveFileDialog1->Filter = "Plik tekstowy (txt) (*.txt)|*.txt| Dowolny plik (*.*) | *.*";
		saveFileDialog1->FileName = "Nazwa";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				this->nazwapliku = saveFileDialog1->FileName;
				System::IO::StreamWriter ^ writer = gcnew System::IO::StreamWriter(saveFileDialog1->FileName);
				writer->Write(tresc->Text);
				writer->Close();
				TextChanged = false;
			}

			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message);
				MessageBox::Show("Zapis zakoñczy³ siê niepowodzeniem.");
			}
		}
	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			if (this->nazwapliku == "")
			{
				saveAsToolStripMenuItem_Click(sender, e);
			}
			else
			{
				System::IO::StreamWriter ^ writer = gcnew System::IO::StreamWriter(this->nazwapliku);
				writer->Write(tresc->Text);
				writer->Close();
				TextChanged = false;
			}
			
		}
		catch (Exception ^ ex)
		{
			MessageBox::Show(ex->Message);
			MessageBox::Show("Zapis zakoñczy³ siê niepowodzeniem.");
		}
}
////  zamykanie u¿ywaj¹c zakoñcz
	private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
////  nowy plik
	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (TextChanged == true)
		{
			String^ message = "Czy chcesz zapisaæ zmiany w pliku " + nazwapliku + " przed otwarciem nowego pliku?";
			String^ caption = "Wa¿ne pytanie";
			MessageBoxButtons buttons = MessageBoxButtons::YesNoCancel;
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(message, caption, buttons);

			if (result == System::Windows::Forms::DialogResult::No)
			{
				this->nazwapliku = "";
				this->tresc->Text = "";
				TextChanged = false;
			}
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				saveToolStripMenuItem_Click(sender, e);
				this->nazwapliku = "";
				this->tresc->Text = "";
				TextChanged = false;
			}
			else
			{

			}
		}
		if (TextChanged == false)
		{
			this->nazwapliku = "";
			this->tresc->Text = "";
			TextChanged = false;
		}
	}	

//// skróty klawiszowe
	private: System::Void tresc_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		{
			if (e->Control && e->KeyCode == Keys::S)
			{
				saveToolStripMenuItem_Click(sender, e);
			}

			if (e->Control && e->KeyCode == Keys::N)
			{
				newToolStripMenuItem_Click(sender, e);
			}
		}
////  zmiana textu
	private: System::Void tresc_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		TextChanged = true;
	}

		/////// MENU EDYCJA ///

	private: System::Void wytnijCtrlXToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		tresc->Cut();
	}
	private: System::Void kopiujCtrlCToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		tresc->Copy();
	}
	private: System::Void wklejCtrlVToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		tresc->Paste();
	}

		/////// MENU FORMAT ///

	private: System::Void zawijanieWierszyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (zawijanieWierszyToolStripMenuItem->Checked == true)
		{
			zawijanieWierszyToolStripMenuItem->Checked = false;
			tresc->WordWrap = false;
		}
		else
		{
			zawijanieWierszyToolStripMenuItem->Checked = true;
			tresc->WordWrap = true;
		}
	}
	private: System::Void zmianaCzcionkiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			tresc->Font = fontDialog1->Font;
			tresc->ForeColor = fontDialog1->Color; // TODO: tresc->ForeColor = fontDialog1->Color; 
		}
	}

		 /////// MENU POMOC ///

private: System::Void oProgramieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		OProgramie^ forma = gcnew OProgramie();
		if (forma->Visible == false)
		{
			forma->ShowDialog();
		}
		
	}

private: System::Void socialMediaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	ProcessStartInfo^ psi = gcnew ProcessStartInfo("https://www.youtube.com/channel/UC0M4kOxz-xB5aTJ4DzCJV3g");
	psi->UseShellExecute = true;
	Process::Start(psi);
}
};
}
