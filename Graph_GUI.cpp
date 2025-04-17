#pragma once

#include "MyForm.h"
#include "Graph.h"
#include <unordered_map>
#include <msclr/marshal_cppstd.h>
#include <cstdlib>
#include <ctime>

namespace DSALABtask1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);

            // Initialize graph and circle positions
            InitializeGraph();
            srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
        }
        Form1(Graph_list a) {
            InitializeComponent();
            pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);

            graph = new Graph_list();
            *graph = a;
            srand(static_cast<unsigned int>(time(0)));
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: Graph_list* graph;
    private: Dictionary<String^, Point>^ vertexPositions;
    private: int radius = 50;  // Radius of the circles
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
               this->SuspendLayout();
               // 
               // pictureBox1
               // 
               this->pictureBox1->BackColor = System::Drawing::Color::White;
               this->pictureBox1->Location = System::Drawing::Point(-1, 0);
               this->pictureBox1->Name = L"pictureBox1";
               pictureBox1->Size = System::Drawing::Size(900, 750);
               this->pictureBox1->TabIndex = 0;
               this->pictureBox1->TabStop = false;
               this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click_1);
               // 
               // Form1
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::LightSteelBlue;
               this->Size = System::Drawing::Size(900, 750);
               this->Controls->Add(this->pictureBox1);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
               this->ImeMode = System::Windows::Forms::ImeMode::KatakanaHalf;
               this->Name = L"Form1";
               this->Text = L"Form1";
               this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
               this->ResumeLayout(false);

           }
#pragma endregion

    private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
    {
    }

    private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    }

    private: void InitializeGraph() {
        // Initialize the graph
        graph = new Graph_list();

        // Add vertices
        graph->insert_vertix("A");
        graph->insert_vertix("B");
        graph->insert_vertix("C");
        graph->insert_vertix("D");
        graph->insert_vertix("E");
        graph->insert_vertix("F");
        graph->insert_vertix("G");
        graph->insert_vertix("I");
        graph->insert_vertix("J");
        graph->insert_vertix("K");
        graph->insert_vertix("H");

        // Add edges
        graph->insert_edge("A", "B");
        graph->insert_edge("A", "C");
        graph->insert_edge("B", "D");
        graph->insert_edge("C", "D");

        // Initialize vertex positions
        vertexPositions = gcnew Dictionary<String^, Point>();
    }

    private: Point GetRandomPosition(int width, int height) {
        int margin = 50; // Margin from the edges
        int x = rand() % (width - 2 * (radius + margin)) + radius + margin;
        int y = rand() % (height - 2 * (radius + margin)) + radius + margin;
        return Point(x, y);
    }

    private: bool IsOverlapping(Point newPoint) {
        for each (KeyValuePair<String^, Point> kvp in vertexPositions) {
            Point existingPoint = kvp.Value;
            int dx = existingPoint.X - newPoint.X;
            int dy = existingPoint.Y - newPoint.Y;
            if (Math::Abs(dx) < 100 && Math::Abs(dy) < 100) {
                return true;
            }
        }
        return false;
    }

    private: Point GetEdgePoint(Point center, Point target) {
        double angle = Math::Atan2(target.Y - center.Y, target.X - center.X);
        return Point(center.X + static_cast<int>(radius * Math::Cos(angle)),
            center.Y + static_cast<int>(radius * Math::Sin(angle)));
    }
          
    private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        System::Drawing::Graphics^ g = e->Graphics;

        // Set rendering hints for better quality
        g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias;
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

        // Create a Pen and a Brush for drawing the circles and filling them.
        System::Drawing::Pen^ myPen = gcnew System::Drawing::Pen(System::Drawing::Color::Black, 2); // Thick black pen
        System::Drawing::SolidBrush^ myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
        System::Drawing::SolidBrush^ textBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);

        // Set the font for the text.
        System::Drawing::Font^ myFont = gcnew System::Drawing::Font("Arial", 12);

        // Create a StringFormat object to center the text.
        System::Drawing::StringFormat^ format = gcnew System::Drawing::StringFormat();
        format->Alignment = System::Drawing::StringAlignment::Center;
        format->LineAlignment = System::Drawing::StringAlignment::Center;

        // Draw vertices
        auto start = graph->getgraph();

        // traverse the graph and draw all verties with atleast 100 spacing and potenciallly no overlaps(may still tho)
        for (auto& vertices : start) {
            String^ vertex = msclr::interop::marshal_as<System::String^>(vertices.val);

            Point position;
            do {
                position = GetRandomPosition(pictureBox1->Width, pictureBox1->Height);
            } while (IsOverlapping(position));

            vertexPositions[vertex] = position;

            System::Drawing::Rectangle rect(position.X - radius, position.Y - radius, 2 * radius, 2 * radius);

            // Draw the circle
            g->FillEllipse(myBrush, rect);
            g->DrawEllipse(myPen, rect);

            // Draw the text inside the circle
            g->DrawString(vertex, myFont, textBrush, rect, format);
        }

        // draw edges for the vertices
        for (auto& vertices : start) {
            String^ vertex = msclr::interop::marshal_as<System::String^>(vertices.val);
            Point center = vertexPositions[vertex];

            std::list<std::string> neighbors = vertices.s;
            for (const std::string& neighbor : neighbors) {
                String^ neighborManaged = gcnew String(neighbor.c_str());
                if (vertexPositions->ContainsKey(neighborManaged)) {
                    Point neighborCenter = vertexPositions[neighborManaged];
                    Point startEdge = GetEdgePoint(center, neighborCenter);
                    Point endEdge = GetEdgePoint(neighborCenter, center);
                    g->DrawLine(myPen, startEdge, endEdge);
                }
            }
        }

        delete myPen;
        delete myBrush;
        delete textBrush;
        delete myFont;
        delete format;
    }
    };
}
