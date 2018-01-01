#include "MyForm.h"
#include "OProgramie.h"
#include <iostream>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Notatnik::MyForm form;
	Application::Run(%form);
}