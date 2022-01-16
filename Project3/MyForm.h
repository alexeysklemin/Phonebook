#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Sql;
	using namespace System::Data::SqlClient;
//	using namespace System::Data::SqlClient::SqlDataReader;


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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FriendName;
	private: System::Windows::Forms::Button^ Refreshbtn;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->FriendName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Refreshbtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->FriendName });
			this->dataGridView1->Location = System::Drawing::Point(12, -2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(333, 378);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// FriendName
			// 
			this->FriendName->HeaderText = L"Name";
			this->FriendName->MinimumWidth = 6;
			this->FriendName->Name = L"FriendName";
			this->FriendName->Width = 125;
			// 
			// Refreshbtn
			// 
			this->Refreshbtn->Location = System::Drawing::Point(1130, 323);
			this->Refreshbtn->Name = L"Refreshbtn";
			this->Refreshbtn->Size = System::Drawing::Size(239, 53);
			this->Refreshbtn->TabIndex = 1;
			this->Refreshbtn->Text = L"Refresh";
			this->Refreshbtn->UseVisualStyleBackColor = true;
			this->Refreshbtn->Click += gcnew System::EventHandler(this, &MyForm::Refreshbtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1381, 377);
			this->Controls->Add(this->Refreshbtn);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void Refreshbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		SqlConnection^ SqlCon = gcnew SqlConnection();
		SqlCommand^ SqlCom = gcnew SqlCommand();
		DataTable^ SqlDt = gcnew DataTable();
		SqlDataAdapter^ SqlDtA = gcnew SqlDataAdapter();
		SqlDataReader^ SqlRd;
		SqlCon->ConnectionString = "Data Source=LAPTOP-ALEX/SQLEXPRESS;Initial Catalog=PhonesFriends;Integrated Security=true";
		SqlCon->Open();
		SqlCom->Connection = SqlCon;
		SqlCom->CommandText = "SELECT FriendName FROM PhonesFriends";
		SqlRd = SqlCom->ExecuteReader();
		SqlDt->Load(SqlRd);
		SqlRd->Close();
		SqlCon->Close();
		dataGridView1->DataSource = SqlDt;

	}
	};
}
