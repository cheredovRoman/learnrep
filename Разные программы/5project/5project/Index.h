#pragma once
#include "indoc.h"
namespace My5project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Index
	/// </summary>
	public ref class Index : public System::Windows::Forms::Form
	{
	public:
		Index(void)
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
		~Index()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ref_button;
	private: System::Windows::Forms::Button^ out_doc;
	protected:

	protected:

	protected:

	protected:


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ in_doc_button;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->in_doc_button = (gcnew System::Windows::Forms::Button());
			this->ref_button = (gcnew System::Windows::Forms::Button());
			this->out_doc = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// in_doc_button
			// 
			this->in_doc_button->Location = System::Drawing::Point(271, 176);
			this->in_doc_button->Name = L"in_doc_button";
			this->in_doc_button->Size = System::Drawing::Size(254, 47);
			this->in_doc_button->TabIndex = 0;
			this->in_doc_button->Text = L"Входные документы";
			this->in_doc_button->UseVisualStyleBackColor = true;
			this->in_doc_button->Click += gcnew System::EventHandler(this, &Index::in_doc_button_Click);
			// 
			// ref_button
			// 
			this->ref_button->Location = System::Drawing::Point(271, 253);
			this->ref_button->Name = L"ref_button";
			this->ref_button->Size = System::Drawing::Size(254, 47);
			this->ref_button->TabIndex = 1;
			this->ref_button->Text = L"Справочники";
			this->ref_button->UseVisualStyleBackColor = true;
			// 
			// out_doc
			// 
			this->out_doc->Location = System::Drawing::Point(271, 342);
			this->out_doc->Name = L"out_doc";
			this->out_doc->Size = System::Drawing::Size(254, 47);
			this->out_doc->TabIndex = 2;
			this->out_doc->Text = L"Выходные документы";
			this->out_doc->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(258, 101);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(267, 31);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Выберите нужную опцию";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Index::textBox1_TextChanged);
			// 
			// Index
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 555);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->out_doc);
			this->Controls->Add(this->ref_button);
			this->Controls->Add(this->in_doc_button);
			this->Name = L"Index";
			this->Text = L"Информационная система спортивных организаций города";
			this->Load += gcnew System::EventHandler(this, &Index::Index_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Index_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void in_doc_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this	->"indoc.h" };
};
}
