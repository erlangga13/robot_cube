/*kelompok 4 IF9*/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>


HDC g_HDC;
float angle = 0.0f;
float legAngle[2] = {1.0f, 1.0f};
float armAngle[2] = {0.0f, 0.0f};
bool fullScreen = false;


void DrawCube(float xPos, float yPos, float zPos)
{
        glPushMatrix();
        glBegin(GL_POLYGON);

                /* tampak atas */
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, -1.0f);
                glVertex3f(-1.0f, 0.0f, -1.0f);
                glVertex3f(-1.0f, 0.0f, 0.0f);

                /* tampak depan */
                glVertex3f(0.0f, 0.0f, 1.0f);
                glVertex3f(-1.0f, 0.0f, 0.0f);
                glVertex3f(-1.0f, -1.0f, 0.0f);
                glVertex3f(0.0f, -1.0f, 0.0f);

                /* tampak sebelah kanan */
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(0.0f, -1.0f, 0.0f);
                glVertex3f(0.0f, -1.0f, -1.0f);
                glVertex3f(0.0f, 0.0f, -1.0f);

                /* tampak sebelah kiri */
                glVertex3f(-1.0f, 0.0f, 0.0f);
                glVertex3f(-1.0f, 0.0f, -1.0f);
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(-1.0f, -1.0f, 0.0f);

                /* tampak bagian bawah */
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(0.0f, -1.0f, -1.0f);
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(-1.0f, -1.0f, 0.0f);

                /* tampak belakang */
                glVertex3f(0.0f, 0.0f, 0.5f);
                glVertex3f(-1.0f, 0.0f, -1.0f);
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(0.0f, -1.0f, -1.0f);

        glEnd();
        glPopMatrix();
}

/* Fungsi: DrawArm
   Tujuan: Fungsi ini menarik lengan untuk robot */

void DrawArm(float xPos, float yPos, float zPos)
{
        glPushMatrix();

                /*  setingan warna 'putih' */
                glColor3f(7.0f, 5.5f, 3.0f);
                glTranslatef(xPos, yPos, zPos);

                /*  1 x 4 x 1 cube */
                glScalef(1.0f, 4.0f, 1.0f);
                DrawCube(0.0f, 5.0f, 0.0f);

        glPopMatrix();
}

/* Fungsi: DrawHead
   Tujuan: Fungsi ini akan menciptakan kepala untuk robot */

void DrawHead(float xPos, float yPos, float zPos)
{
        glPushMatrix();

                /* setingan warna 'putih' */
                glColor3f(1.0f, 1.0f, 1.0f);
                glTranslatef(xPos, yPos, zPos);

                /* 2 x 2 x 2 cube */
                glScalef(2.0f, 2.0f, 2.0f);
                DrawCube(0.0f, 0.0f, 0.0f);

        glPopMatrix();
}

/*  Fungsi: DrawTorso
    Tujuan: Fungsi akan melakukan seperti yang disarankan dan menggambar tubuh robot
*/

void DrawTorso(float xPos, float yPos, float zPos)
{
        glPushMatrix();

                /* setingan warna 'biru' */
                glColor3f(1.0f, 0.0f, 0.0f);
                glTranslatef(xPos, yPos, zPos);

                /* 3 x 5 x 1 cube */
                glScalef(3.0f, 5.0f, 1.0f);
                DrawCube(0.0f, 0.0f, 0.0f);

        glPopMatrix();
}

/*  Fungsi: DrawLeg
    Tujuan: Tidak terdengar repetitve, 
    tetapi seperti yang disarankan fungsi ini akan menarik kaki robot */

void DrawLeg(float xPos, float yPos, float zPos)
{
        glPushMatrix();

                /* setingan warna 'kuning' */
                glColor3f(1.0f, 0.0f, 0.0f);
                glTranslatef(xPos, yPos, zPos);

                /* 1 x 5 x 1 cube */
                glScalef(1.0f, 5.0f, 1.0f);
                DrawCube(0.0f, 0.0f, 0.0f);

        glPopMatrix();
}

/* Fungsi: DrawRobot
   Tujuan: untuk menarik seluruh robot */

void DrawRobot(float xPos, float yPos, float zPos)
{
        /* Variabel untuk keadaan kaki dan tangan robot */
        static bool leg1 = true;
        static bool leg2 = false;
        static bool arm1 = true;
        static bool arm2 = false;

        glPushMatrix();

                /* Ini akan menarik robot pada koordinat yang diinginkan */
                glTranslatef(xPos, yPos, zPos);

                /* Ketiga garis akan menarik berbagai komponen dari robot */
                DrawHead(1.0f, 2.0f, 0.0f);
                DrawTorso(1.5f, 0.0f, 0.0f);
                glPushMatrix();


                /* Jika lengan bergerak maju kita akan meningkatkan
                   sudut, jika tidak, kami akan menurunkan sudut */
                if (arm1)
                {
                        armAngle[0] = armAngle[0] + 1.0f;
                }
                else
                {
                        armAngle[0] = armAngle[0] - 1.0f;
                }

                /* Setelah lengan telah mencapai sudut maksimal dalam satu arah,
                   kami ingin membalikkan dan mengubah arah */
                if (armAngle[0] >= 15.0f)
                {
                        arm1 = false;
                }
                if (armAngle[0] <= -15.0f)
                {
                        arm1 = true;
                }


                /* Di sini lengan bergerak menjauh dari batang tubuh. 
                   seakan membuat efek berjalan */
                glTranslatef(0.0f, -0.5f, 0.0f);
                glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);
                DrawArm(2.5f, 0.0f, -0.5f);

        glPopMatrix();

        glPushMatrix();


                /* Jika lengan bergerak maju, maka akan meningkatkan sudut. 
                   kalau tidak, maka akan menurunkan sudut */
                if (arm2)
                {
                        armAngle[1] = armAngle[1] + 1.0f;
                }
                else
                {
                        armAngle[1] = armAngle[1] - 1.0f;
                }

                /* Setelah lengan telah mencapai sudut maksimal dalam satu arah,
                   kami ingin membalikkan dan mengubah arah */
                if (armAngle[1] >= 15.0f)
                {
                        arm2 = false;
                }
                if (armAngle[1] <= -15.0f)
                {
                        arm2 = true;
                }

                /* lengan bergerak menjauh dari batang tubuh. 
                   ini akan membuat efek berjalan */
                glTranslatef(0.0f, -0.5f, 0.0f);
                glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);
                DrawArm(-1.5f, 0.0f, -0.5f);

        glPopMatrix();

        /* Sekarang waktunya untuk memutar kaki yang relatif terhadap robot */
        glPushMatrix();

                /* Jika kaki bergerak ke depan kita akan meningkatkan sudut.
                   jika tidak, maka akan menurunkan sudut */
                if (leg1)
                {
                        legAngle[0] = legAngle[0] + 1.0f;
                }
                else
                {
                        legAngle[0] = legAngle[0] - 1.0f;
                }

                /* Setelah kaki telah mencapai sudut maksimum dalam satu arah,
                   robot ingin membalikkan dan mengubah arah */
                if (legAngle[0] >= 15.0f)
                {
                        leg1 = false;
                }
                if (legAngle[0] <= -15.0f)
                {
                        leg1 = true;
                }


                /* kaki bergerak menjauh dari batang tubuh dan memutar. 
                   ini akan membuat efek berjalan */
                glTranslatef(0.0f, -0.5f, 0.0f);
                glRotatef(legAngle[0], 1.0f, 0.0f, 0.0f);


                /* Waktu untuk menarik kaki */
                DrawLeg(-0.5f, -5.0f, -0.5f);

        glPopMatrix();

        /* Sama seperti di atas, untuk kaki kiri */
        glPushMatrix();

                /* Jika kaki bergerak ke depan, kita akan meningkatkan sudut, 
                   kalau tidak sudut akan di turunkan */
                if (leg2)
                {
                        legAngle[1] = legAngle[1] + 1.0f;
                }
                else
                {
                        legAngle[1] = legAngle[1] - 1.0f;
                }

                /* Setelah kaki telah mencapai sudut maksimum dalam satu arah, 
                   kami ingin membalikkan dan mengubah arah */
                if (legAngle[1] >= 15.0f)
                {
                        leg2 = false;
                }
                if (legAngle[1] <= -15.0f)
                {
                        leg2 = true;
                }

                /* kaki bergerak jauh dari batang tubuh dan memutar. 
                   ini akan membuat efek berjalan */
                glTranslatef(0.0f, -0.5f, 0.0f);
                glRotatef(legAngle[1], 1.0f, 0.0f, 0.0f);
                DrawLeg(1.5f, -5.0f, -0.5f);

        glPopMatrix();

        glPopMatrix();

}

/* Fungsi: Render
   Tujuan: Fungsi ini akan bertanggung jawab untuk rendering */
void Render()
{
        /* Memungkinkan pengujian mendalam */
        glEnable(GL_DEPTH_TEST);

        /* Berikut render. Menghapus layar menjadi hitam,
           jelas warna dan buffer kedalaman, dan me-reset matriks modelview */
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        /* Meningkatkan kontra rotasi sudut */
        angle = angle + 1.0f;

        /* Reset setelah kami telah menyelesaikan lingkaran */
        if (angle >= 360.0f)
        {
                angle = 0.0f;
        }

        glPushMatrix();
                glLoadIdentity();

                /* Pindah ke 0,0, -30, memutar robot pada sumbu y-nya, 
                   menggambar robot, dan membuang dari matriks saat ini */
                glTranslatef(0.0f, 0.0f, -30.0f);
                glRotatef(angle, 0.0f, 1.0f, 0.0f);
                DrawRobot(0.0f, 0.0f, 0.0f);
        glPopMatrix();

        glFlush();

        /* Membawa kembali ke latar depan penyangga */
        SwapBuffers(g_HDC);
}


/* Fungsi: SetupPixelFormat
   Tujuan: Fungsi ini akan bertanggung jawab untuk menetapkan format piksel untuk
   perangkat konteks */
void SetupPixelFormat(HDC hDC)
{
        /* Pixel format index */
        int nPixelFormat;

        static PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),          //ukuran struktur
                1,                                      //versi standar 
                PFD_DRAW_TO_WINDOW |                    //dukungan jendela gambar 
                PFD_SUPPORT_OPENGL |                    //dukungan openGL 
                PFD_DOUBLEBUFFER,                       //dukungan ganda penyangga 
                PFD_TYPE_RGBA,                          //warna mode RGBA 
                32,                                     //mode warna 32 bit 
                0, 0, 0, 0, 0, 0,                       //mengabaikan warna bit 
                0,                                      //tidak ada buffer alfa
                0,                                      //bit bergeser sedikit
                0,                                      //akumulasi tidak ada buffer 
                0, 0, 0, 0,                             //mengabaikan akumulasi bit 
                16,                                     //buffer ukuran - 16 bit z
                0,                                      //tidak ada buffer stensil
                0,                                      //no aux buffer
                PFD_MAIN_PLANE,                         //gambar utama
                0,                                      //dilindungi
                0, 0, 0 };                              //lapisan pelindung diabaikan

                /*  Memilih format terbaik yang cocok */
                nPixelFormat = ChoosePixelFormat(hDC, &pfd);

                /* Mengatur format piksel dengan konteks perangkat*/
                SetPixelFormat(hDC, nPixelFormat, &pfd);
}

/* Prosedur Windows Event Handler */
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        /* Rendering dan Konteks Perangkat variabel dideklarasikan di sini */
        static HGLRC hRC;
        static HDC hDC;

        /* Lebar dan Tinggi jendela robot adalah menjadi tampilan masuk */
        int width, height;

        switch(message)
        {
                case WM_CREATE: //jendela yang diciptakan

                        hDC = GetDC(hwnd);  //mendapatkan perangkat konteks
                        g_HDC = hDC;
                        SetupPixelFormat(hDC); //memanggil format piksel fungsi pengaturan

                        /* Buat konteks rendering */
                        hRC = wglCreateContext(hDC);
                        wglMakeCurrent(hDC, hRC);

                        return 0;
                        break;

                case WM_CLOSE:  //menutup jendela

                        /* Hapus render konteks dan menghapusnya*/
                        wglMakeCurrent(hDC, NULL);
                        wglDeleteContext(hRC);

                        /* Kirim pesan ke antrian berhenti */
                        PostQuitMessage(0);

                        return 0;
                        break;

                case WM_SIZE:

                        /* Ambil lebar dan tinggi*/
                        height = HIWORD(lParam);
                        width = LOWORD(lParam);

                        /* jangan di bagi dengan 0*/
                        if (height == 0)
                        {
                                height = 1;
                        }

                        /* Reset viewport ke dimensi baru */
                        glViewport(0, 0, width, height);

                        /* Set Matrix saat ini untuk proyeksi */
                        glMatrixMode(GL_PROJECTION);
                        glLoadIdentity(); //ulang matriks proyeksi

                        /* Waktu untuk menghitung rasio aspek di jendela */
                        gluPerspective(54.0f, (GLfloat)width/(GLfloat)height, 1.0f, 1000.0f);

                        glMatrixMode(GL_MODELVIEW); //mengatur model tampilan matriks
                        glLoadIdentity(); //mengatur ulang model pandangan matriks

                        return 0;
                        break;

                default:

                        break;
        }

        return (DefWindowProc(hwnd, message, wParam, lParam));
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
        WNDCLASSEX windowClass; //kelas window
        HWND    hwnd;                   //pegangan jendela
        MSG             msg;                    //pesan
        bool    done;                   //bendera untuk menyelesaikan aplikasi
        DWORD   dwExStyle;              //jendela perpanjang gaya
        DWORD   dwStyle;                //gaya jendela
        RECT    windowRect;

        /* Screen / layar atribut */
        int width = 800;
        int height = 600;
        int bits = 32;

        windowRect.left =(long)0;               //mengatur nilai kiri ke 0
        windowRect.right =(long)width;  //mengatur nilai hak untuk lebar yang diminta
        windowRect.top =(long)0;                //mengatur nilai atas ke 0
        windowRect.bottom =(long)height;//menetapkan nilai bawah ke ketinggian yang diminta

        /* Isilah struktur kelas window */
        windowClass.cbSize                      = sizeof(WNDCLASSEX);
        windowClass.style                       = CS_HREDRAW | CS_VREDRAW;
        windowClass.lpfnWndProc         = WndProc;
        windowClass.cbClsExtra          = 0;
        windowClass.cbWndExtra          = 0;
        windowClass.hInstance           = hInstance;
        windowClass.hIcon                       = LoadIcon(NULL, IDI_APPLICATION);
        windowClass.hCursor                     = LoadCursor(NULL, IDC_ARROW);
        windowClass.hbrBackground       = NULL;
        windowClass.lpszMenuName        = NULL;
        windowClass.lpszClassName       = "MyClass";
        windowClass.hIconSm                     = LoadIcon(NULL, IDI_WINLOGO);

        /* Daftar jendela kelas */
        if (!RegisterClassEx(&windowClass))
        {
                return 0;
        }

        /* Periksa apakah fullscreen masih on */
        if (fullScreen)
        {
                DEVMODE dmScreenSettings;
                memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
                dmScreenSettings.dmSize = sizeof(dmScreenSettings);
                dmScreenSettings.dmPelsWidth = width;   //layar lebar
                dmScreenSettings.dmPelsHeight = height; //layar tinggi
                dmScreenSettings.dmBitsPerPel = bits;   //bits per pixel
                dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

                if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN !=
                                                                  DISP_CHANGE_SUCCESSFUL))
                {
                        /* Mengatur mode tampilan gagal, beralih ke jendela */
                        MessageBox(NULL, "Display mode failed", NULL, MB_OK);
                        fullScreen = false;
                }
        }

        /* Periksa apakah fullscreen masih on */
        if (fullScreen)
        {
                dwExStyle = WS_EX_APPWINDOW;    //jendela perpanjang gaya
                dwStyle = WS_POPUP;                             //gaya jendela
                ShowCursor(FALSE);                              //hide mouse pointer
        }

        else
        {
                dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE; //jendela perpanjang gaya
                dwStyle = WS_OVERLAPPEDWINDOW;                                  //windows style
        }

        AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);

        /* Kelas register, sekarang membuat jendela */
        hwnd = CreateWindowEx(NULL, "MyClass",  //nama kelas
                                                  "OpenGL Robot",       //nama aplikasi
                                                  dwStyle |
                                                  WS_CLIPCHILDREN |
                                                  WS_CLIPSIBLINGS,
                                                  0, 0,                         //x dan y coords
                                                  windowRect.right - windowRect.left,
                                                  windowRect.bottom - windowRect.top,//lebar, tinggi
                                                  NULL,                 //menangani untuk orang
                                                  NULL,                 //menangani ke menu
                                                  hInstance,    //contoh aplikasi
                                                  NULL);                //ada tambahan params

        /* Periksa apakah penciptaan jendela gagal (hwnd = null ?)*/
        if (!hwnd)
        {
                return 0;
        }

        ShowWindow(hwnd, SW_SHOW);      //menampilkan jendela
        UpdateWindow(hwnd);                     //memperbarui jendela

        done = false;   //menginisialisasi kondisi variabel loop 

        /* pesan utama lingkaran*/
        while (!done)
        {
                PeekMessage(&msg, hwnd, NULL, NULL, PM_REMOVE);

                        if (msg.message == WM_QUIT)     //apakah kita menerima pesan berhenti?
                        {
                                done = true;
                        }

                        else
                        {
                                Render();
                                TranslateMessage(&msg);
                                DispatchMessage(&msg);
                        }
        }

        if (fullScreen)
        {
                ChangeDisplaySettings(NULL, 0);
                ShowCursor(TRUE);
        }

        return msg.wParam;

}

