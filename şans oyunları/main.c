#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
 //ANA MENÜ İÇİN
    int puan=0;
    int sapuan=0;
    int stpuan=0;
    int onpuan=0;
    int supuan=0;
    char cikis;
    Anamenu:

    printf("\n \t \t \t \t \t \t  ANA MENU\n");
    printf("\n \n \t 1- SANS OYUNLARI \n");
    printf(" \t 2- CEKILIS ISTATIKLARI \n");
    printf(" \t 3- CIKIS\n");
    int secim;
    Anamenusecimi1:
    printf("\n SECIMINIZI GIRINIZ :");
    scanf("%d",&secim);
    //GİRİLEN DEĞER KONTROL EDİLMELİ!
       if (secim<1 || secim>3)
     {
        printf(" \n Sadece 1,2 veya 3'u secebilirsiniz! \n");
        goto Anamenusecimi1;
     }

    switch (secim)
    {
case 1:
  {  altmenu:
       //ŞANS OYUNLARI ALT MENÜSÜ
    printf("\n \n \t \t \t \t \t SANS OYUNLARI ALT MENUSU \n");
    printf("\n \n \t 1- SAYISAL LOTO OYNAMA \n");
    printf(" \t 2- SANS TOPU OYNAMA \n");
    printf(" \t 3- ON NUMARA OYNAMA \n");
    printf(" \t 4- SUPER LOTO OYNAMA \n");
    printf(" \t 5- Ana menu \n");
    printf(" \t \t \t \t \t \t \t \t \t \t TOPLAM ODULUNUZ : %d",puan);

    int secim2;
    SansoyunlarisecimiA1:
         printf("\n SECIMINIZI GIRINIZ :");
    scanf("%d",&secim2);
    //GİRİLEN DEĞER KONTROL EDİLMELİ!
       if (secim2<1 || secim2>5)
     {
        printf(" \n Sadece 1,2,3,4 veya 5'i secebilirsiniz! \n");
        goto SansoyunlarisecimiA1;
     }
       /* SAYISAL LOTO OYNAMA 1Aa */

      if(secim2==1)
      {    Aa1:
           printf("\n \n \t \t \t \t \t SAYISAL LOTO OYNAMA \n");
            printf(" \n  [1-49] araliginda, birbirinden farkli 6 sayi giriniz.\n");
            int A1[6];
            int i;
              for( i=0;i<6;i++)
           {
               Sayisallotosecimi1:
               printf("SAYI %d: ",(i+1));
               scanf("%d",&A1[i]);
                if(A1[i]<1||A1[i]>49)
                {
                    printf("Girilen degerler [1-49] araliginda olmalidir!!! \n");
                    goto Sayisallotosecimi1;
                }
                //kontrol kısmı aynı sayıyı girmesin
                 for(int j=0;j<6;j++)
                   {   if(i==j)
                         break;
                         else if(A1[i]==A1[j])
                         {
                              printf("Girilen degerler birbirlerinden farkli olmalidir!!! \n");
                        goto Sayisallotosecimi1;

                         }
                     }
           }

              printf("LOTO SONUCLARI :\n");

              //RASTGELE SAYI DİZİMİZ
              int  rastgele[6];
              srand(time(NULL));
                  for(i=0;i<6;i++)
                  {
					SayisallotosecimiRn:
			  // RASTGELE SAYI UYDURMA KISMI
                     rastgele[i]=1+rand()%49;
                     for(int j=0;j<6;j++)
					{	if(i==j)
						break;
						else if(rastgele[i]==rastgele[j])
						goto SayisallotosecimiRn;
					 }
					 printf("Loto [%d]:%d \n",(i+1),rastgele[i]);
                  }
         //DİZİLERİN KÜÇÜKTEN BÜYÜĞE SIRALANMASI
                     int gecici;
                      for(int i=0; i<6;i++)
                    {
                    for(int j=i+1; j<6; j++)
                    {
                       if(A1[i] > A1[j])
                     {
                        gecici = A1[i];
                        A1[i] = A1[j];
                        A1[j] = gecici;
                     }
                    }
                    }
                    printf(" \n ------>Sizin sayilariniz :");
                    for(int i=0; i<6; i++)
                    printf("%d ", A1[i]);

                    int gecici2;
                      for(int i=0; i<6;i++)
                    {
                    for(int j=i+1; j<6; j++)
                    {
                        if(rastgele[i] > rastgele[j])
                     {
                    gecici2 = rastgele[i];
                    rastgele[i] = rastgele[j];
                    rastgele[j] = gecici2;
                     }
                    }

                    }
                    printf(" \n ----->Loto sonuclari :");
                    for(int i=0; i<6; i++)
                    {
                      printf("%d ", rastgele[i]);
                    }

                // İKİ DİZİNİN KARŞILAŞTIRILMASI******
                 int sayac=0;
                for(i=0;i<6;i++)
                {
                   for(int j=0;j<6;j++)
                     if(A1[i]==rastgele[j])
                    {
                        sayac++;
                    }

                }
               printf(" \n  --------> TUTTURDUGUNUZ SAYI ADEDI :%d",sayac);
               //PUAN HESABI

                if(sayac==3)
                {
                    puan+=32;
                    sapuan+=32;
                      printf("\n --------> PUANINIZ :%d",32);
                      printf("\n ---> SAYISAL LOTO TOPLAM PUANINIZ :%d",sapuan);
                }

                else if(sayac==4)
                {
                    puan+=64;
                    sapuan+=64;
                    printf("\n --------> PUANINIZ :%d",64);
                    printf("\n ---> SAYISAL LOTO TOPLAM PUANINIZ :%d",sapuan);
                }

                else if(sayac==5)
                {
                    puan+=128;
                    sapuan+=128;
                    printf("\n -------->PUANINIZ :%d",128);
                    printf("\n ---> SAYISAL LOTO TOPLAM PUANINIZ :%d",sapuan);
                }

                else if(sayac==6)
                {
                    puan+=256;
                    sapuan+=256;
                     printf("\n --------> PUANINIZ :%d",256);
                     printf("\n ---> SAYISAL LOTO TOPLAM PUANINIZ :%d",sapuan);
                }

                else
                    {
                    printf("\n --------> PUAN KAZANAMADINIZ");
                    printf("\n ---> SAYISAL LOTO TOPLAM PUANINIZ :%d",sapuan);
                     }
                //TEKRAR OYNAYACAK MI?
                char sec;
                SEC1:
                printf("\n \t \t \t \t TEKRAR OYNAMAK ISTER MISINIZ ([E]vet,[H]ayir)\n-->");
                scanf("%s",&sec);
                 if(sec=='e'||sec=='E')
                    goto Aa1;
                 else if(sec=='h'||sec=='H')
                    goto altmenu;
                else{
                    printf("Sadece e,E veya h,H yazabilirsiniz!!!");
                    goto SEC1;
                    }


        }


 if(secim2==2)//ŞANS TOPU OYNAMA   1Ab  ********************************************
      {    Ab1:
           printf("\n \n \t \t \t \t \t SANS TOPU OYNAMA \n");
            printf(" \n  [1-34] araliginda, birbirinden farkli 5 sayi giriniz.\n");
            int A2[5];
            int i;
              for( i=0;i<5;i++)
           {
               Sanstopuoynama1:
               printf("SAYI %d: ",(i+1));
               scanf("%d",&A2[i]);
                if(A2[i]<1||A2[i]>34)
                {
                    printf("Girilen degerler [1-34] araliginda olmalidir!!! \n");
                    goto Sanstopuoynama1;
                }
                //kontrol kısmı aynı sayıyı girmesin*************************************************************

                 for(int j=0;j<5;j++)
                   {   if(i==j)
                         break;
                         else if(A2[i]==A2[j])
                         {
                              printf("Girilen degerler birbirlerinden farkli olmalidir!!! \n");
                        goto Sanstopuoynama1;

                         }
                     }
              }
              //ek sayisi +1
               int eksayi;
            eksayisecimi:
            printf(" \n [1-14] arasindaki +1 ek sayinizi giriniz:");
            scanf("%d",&eksayi);
            A2[5]=eksayi;
            if(eksayi<1||eksayi>14)
            {
                printf("\n Girilen deger [1-14] arasinda olmalidir !!!");
                goto eksayisecimi;
            }


              printf("LOTO SONUCLARI :\n");

              //RASTGELE SAYI DİZİMİZ
              int  rastgele[6];
              srand(time(NULL));
                  for(i=0;i<5;i++)
                  {   // RASTGELE SAYI UYDURMA KISMI

                     superlotorandom:
                     rastgele[i]=1+rand()%34;
                     for(int j=0;j<5;j++)
                     {
                      if(i==j)
                        break;
                      else if(rastgele[i]==rastgele[j])
                        goto superlotorandom;
                     }
                     printf("Loto [%d]:%d \n",(i+1),rastgele[i]);
                  }
                  //ek restgelemiz 6.dizi elemanı
                      rastgele[5]=1+rand()%14;
                      printf("+1 Ek Loto Sonucu:%d \n",rastgele[5]);


                       //DİZİLERİN KÜÇÜKTEN BÜYÜĞE SIRALANMASI**************
                   int gecici;
                      for(int i=0; i<5;i++)
                    {
                       for(int j=i+1; j<5; j++)
                    {
                       if(A2[i] > A2[j])
                     {
                        gecici = A2[i];
                        A2[i] = A2[j];
                        A2[j] = gecici;
                     }
                    }
                    }
                    printf(" \n ------>Sizin sayilariniz :");
                    for(int i=0; i<5; i++)
                    printf("%d ", A2[i]);
                    printf("\t  +1 ek sayiniz :%d",A2[5]);


                    int gecici2;
                      for(int i=0; i<5;i++)
                    {
                    for(int j=i+1; j<5; j++)
                    {
                        if(rastgele[i] > rastgele[j])
                     {
                    gecici2 = rastgele[i];
                    rastgele[i] = rastgele[j];
                    rastgele[j] = gecici2;
                     }
                    }

                    }
                    printf(" \n ----->Loto sonuclari :");
                    for(int i=0; i<5; i++)
                      printf("%d ", rastgele[i]);
                    printf(" \t  +1 ek loto sonucu:%d ",rastgele[5]);

            //iki dizinin karsılastırılması

             int sayac=0;
                for(i=0;i<5;i++)
                {
                   for(int j=0;j<5;j++)
                     if(A2[i]==rastgele[j])
                    {
                        sayac++;
                    }

                }
                printf(" \n  --------> TUTTURDUGUNUZ SAYI ADEDI :%d",sayac);
                int ek=0;
                if(rastgele[5]==A2[5])
                {
                    printf(" \n Tebrikler +1 ek sayiyi tutturdunuz.");
                    ek=1;
                }

          // puan

         if(sayac==1&&ek==1)
                {
                    puan+=2;
                    stpuan+=2;
                      printf("\n --------> PUANINIZ :%d",2);
                      printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }

                else if(sayac==2&&ek==1)
                {
                    puan+=4;
                    stpuan+=4;
                    printf("\n --------> PUANINIZ :%d",4);
                    printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }
                 else if(sayac==3&&ek==1)
                {
                    puan+=16;
                    stpuan+=16;
                     printf("\n --------> PUANINIZ :%d",16);
                     printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }

                else if(sayac==3)
                {
                    puan+=8;
                    stpuan+=8;
                    printf("\n -------->PUANINIZ :%d",8);
                    printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }


                  else if(sayac==4&&ek==1)
                {
                    puan+=64;
                    stpuan+=+64;
                     printf("\n --------> PUANINIZ :%d",64);
                     printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }
                 else if(sayac==4)
                {
                    puan+=32;
                    stpuan+=32;
                     printf("\n --------> PUANINIZ :%d",32);
                     printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }
                  else if(sayac==5&&ek==1)
                {
                    puan+=256;
                    stpuan+=256;
                     printf("\n --------> PUANINIZ :%d",256);
                     printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }
                  else if(sayac==5)
                {
                    puan+=128;
                    stpuan+=128;
                     printf("\n --------> PUANINIZ :%d",128);
                     printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                }

                else
                    {
                    printf("\n --------> PUAN KAZANAMADINIZ");
                    printf("\n ---> SANS TOPU TOPLAM PUANINIZ :%d",stpuan);
                     }


               //TEKRAR OYNAYACAK MI?
                char sec;
                SEC2:
                printf("\n \t \t \t \t TEKRAR OYNAMAK ISTER MISINIZ ([E]vet [H]ayir)\n\a-->");
                scanf("%s",&sec);
                 if(sec=='e'||sec=='E')
                    goto Ab1;
                 else if(sec=='h'||sec=='H')
                    goto altmenu;
                else{
                    printf("Sadece e,E veya h,H yazabilirsiniz!!!");
                    goto SEC2;
                    }

      }
       if(secim2==3)//ON NUMARA OYNAMA   1Ac  ***************************************
      {
        Ac1:
           printf("\n \n \t \t \t \t \t ON NUMARA OYNAMA \n");
            printf(" \n  [1-80] araliginda, birbirinden farkli 10 sayi giriniz.\n");
            int A3[10];
            int i;
              for( i=0;i<10;i++)
           {
               Onnumaraoynamasecimi1:
               printf("SAYI %d: ",(i+1));
               scanf("%d",&A3[i]);
                if(A3[i]<1||A3[i]>80)
                {
                    printf("Girilen degerler [1-80] araliginda olmalidir!!! \n");
                    goto Onnumaraoynamasecimi1;
                }
                //kontrol kısmı aynı sayıyı girmesin
                 for(int j=0;j<10;j++)
                   {   if(i==j)
                         break;
                         else if(A3[i]==A3[j])
                         {
                              printf("Girilen degerler birbirlerinden farkli olmalidir!!! \n");
                        goto Onnumaraoynamasecimi1;

                         }
                     }
           }

              printf("LOTO SONUCLARI :\n");

              //RASTGELE SAYI DİZİMİZ
              int  rastgele[22];
              srand(time(NULL));
                  for(i=0;i<22;i++)
                  {   // RASTGELE SAYI UYDURMA KISMI
                     onnumararastgele:
                     rastgele[i]=1+rand()%80;
                     for(int j=0;j<22;j++)
                     {
                         if(i==j) break;
                         else if(rastgele[i]==rastgele[j])
                         goto onnumararastgele;
                     }
                     printf("Loto [%d]:%d \n",(i+1),rastgele[i]);
                  }
         //DİZİLERİN KÜÇÜKTEN BÜYÜĞE SIRALANMASI
                     int gecici;
                      for(int i=0; i<10;i++)
                    {
                    for(int j=i+1; j<10; j++)
                    {
                       if(A3[i] > A3[j])
                     {
                        gecici = A3[i];
                        A3[i] = A3[j];
                        A3[j] = gecici;
                     }
                    }
                    }
                    printf(" \n ------>Sizin sayilariniz :");
                    for(int i=0; i<10; i++)
                    printf("%d ", A3[i]);

                    int gecici2;
                      for(int i=0; i<22;i++)
                    {
                    for(int j=i+1; j<22; j++)
                    {
                        if(rastgele[i] > rastgele[j])
                     {
                    gecici2 = rastgele[i];
                    rastgele[i] = rastgele[j];
                    rastgele[j] = gecici2;
                     }
                    }

                    }
                    printf(" \n ----->Loto sonuclari :");
                    for(int i=0; i<22; i++)
                    {
                      printf("%d ", rastgele[i]);
                    }

                // İKİ DİZİNİN KARŞILAŞTIRILMASI******

                 int sayac=0;
                for(i=0;i<10;i++)
                {
                    for(int j=0;j<22;j++)
                        if(A3[i]==rastgele[j])
                    {
                        sayac++;
                    }

                }
               printf(" \n  --------> TUTTURDUGUNUZ SAYI ADEDI :%d",sayac);
               //PUAN HESABI

                if(sayac==0)
                {
                    puan+=8;
                      printf("\n --------> PUANINIZ :%d",8);
                      printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                }

                else if(sayac==6)
                {
                    puan+=16;
                    printf("\n --------> PUANINIZ :%d",16);
                    printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                }

                else if(sayac==7)
                {
                    puan+=32; onpuan+=32;
                    printf("\n -------->PUANINIZ :%d",32);
                    printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                }

                else if(sayac==8)
                {
                    puan+=64; onpuan+=64;
                     printf("\n --------> PUANINIZ :%d",64);
                     printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                }
                else if(sayac==9)
                {
                    puan+=128; onpuan+=128;
                     printf("\n --------> PUANINIZ :%d",128);
                     printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                }
                else if(sayac==10)
                {
                    puan+=256; onpuan+=256;
                     printf("\n --------> PUANINIZ :%d",256);
                     printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                }

                else
                    {
                    printf("\n --------> PUAN KAZANAMADINIZ");
                    printf("\n ---> ON NUMARA TOPLAM PUANINIZ :%d",onpuan);
                     }
                //TEKRAR OYNAYACAK MI?
                char sec;
                SEC3:
                printf("\n \t \t \t \t TEKRAR OYNAMAK ISTER MISINIZ ([E]vet [H]ayir)\n\a-->");
                scanf("%s",&sec);
                 if(sec=='e'||sec=='E')
                    goto Ac1;
                 else if(sec=='h'||sec=='H')
                    goto altmenu;
                else{
                    printf("Sadece e,E veya h,H yazabilirsiniz!!!");
                    goto SEC3;
                    }


        }


       if(secim2==4)//**************SÜPER LOTO OYNAMA****************************
      {    Ad1:
           printf("\n \n \t \t \t \t \t SUPER LOTO OYNAMA \n");
            printf(" \n  [1-54] araliginda, birbirinden farkli 6 sayi giriniz.\n");
            int A4[6];
            int i;
              for( i=0;i<6;i++)
           {
               Superlotosecimi1:
               printf("SAYI %d: ",(i+1));
               scanf("%d",&A4[i]);
                if(A4[i]<1||A4[i]>54)
                {
                    printf("Girilen degerler [1-54] araliginda olmalidir!!! \n");
                    goto Superlotosecimi1;
                }
                //kontrol kısmı aynı sayıyı girmesin
                 for(int j=0;j<6;j++)
                   {   if(i==j)
                         break;
                         else if(A4[i]==A4[j])
                         {
                              printf("Girilen degerler birbirlerinden farkli olmalidir!!! \n");
                        goto Superlotosecimi1;

                         }
                     }
           }

              printf("LOTO SONUCLARI :\n");

              //RASTGELE SAYI DİZİMİZ
              int  rastgele[6];
              srand(time(NULL));
                  for(i=0;i<6;i++)
                  {   // RASTGELE SAYI UYDURMA KISMI
                     superlotorastgele:
                     rastgele[i]=1+rand()%54;
                     for(int j=0;j<6;j++)
                     {
                         if(i==j) break;
                         else if(rastgele[i]==rastgele[j])
                         goto superlotorastgele;
                     }
                     printf("Loto [%d]:%d \n",(i+1),rastgele[i]);
                  }
         //DİZİLERİN KÜÇÜKTEN BÜYÜĞE SIRALANMASI
                     int gecici;
                      for(int i=0; i<6;i++)
                    {
                    for(int j=i+1; j<6; j++)
                    {
                       if(A4[i] > A4[j])
                     {
                        gecici = A4[i];
                        A4[i] = A4[j];
                        A4[j] = gecici;
                     }
                    }
                    }
                    printf(" \n ------>Sizin sayilariniz :");
                    for(int i=0; i<6; i++)
                    printf("%d ", A4[i]);

                    int gecici2;
                      for(int i=0; i<6;i++)
                    {
                    for(int j=i+1; j<6; j++)
                    {
                        if(rastgele[i] > rastgele[j])
                     {
                    gecici2 = rastgele[i];
                    rastgele[i] = rastgele[j];
                    rastgele[j] = gecici2;
                     }
                    }

                    }
                    printf(" \n ----->Loto sonuclari :");
                    for(int i=0; i<6; i++)
                    {
                      printf("%d ", rastgele[i]);
                    }

                // İKİ DİZİNİN KARŞILAŞTIRILMASI******
                 int sayac=0;
                for(i=0;i<6;i++)
                {
                   for(int j=0;j<6;j++)
                     if(A4[i]==rastgele[j])
                    {
                        sayac++;
                    }

                }
               printf(" \n  --------> TUTTURDUGUNUZ SAYI ADEDI :%d",sayac);
               //PUAN HESABI

                if(sayac==3)
                {
                    puan+=32; supuan+=32;
                      printf("\n --------> PUANINIZ :%d",32);
                      printf("\n ---> SUPER LOTO TOPLAM PUANINIZ :%d",supuan);
                }

                else if(sayac==4)
                {
                    puan+=64; supuan+=64;
                    printf("\n --------> PUANINIZ :%d",64);
                    printf("\n ---> SUPER LOTO TOPLAM PUANINIZ :%d",supuan);
                }

                else if(sayac==5)
                {
                    puan+=128; supuan+=128;
                    printf("\n -------->PUANINIZ :%d",128);
                    printf("\n ---> SUPER LOTO TOPLAM PUANINIZ :%d",supuan);
                }

                else if(sayac==6)
                {
                    puan+=256; supuan+=256;
                     printf("\n --------> PUANINIZ :%d",256);
                     printf("\n ---> SUPER LOTO TOPLAM PUANINIZ :%d",supuan);
                }

                else
                    {
                    printf("\n --------> PUAN KAZANAMADINIZ");
                    printf("\n ---> SUPER LOTO TOPLAM PUANINIZ :%d",supuan);
                     }
                //TEKRAR OYNAYACAK MI?
                char sec;
                SEC4:
                printf("\n \t \t \t \t TEKRAR OYNAMAK ISTER MISINIZ ([H]ayir [E]vet)\n\a-->");
                scanf("%s",&sec);
                 if(sec=='e'||sec=='E')
                    goto Ad1;
                 else if(sec=='h'||sec=='H')
                    goto altmenu;
                else{
                    printf("Sadece e,E veya h,H yazabilirsiniz!!!");
                    goto SEC4;
                    }

        }

         if(secim2==5)//************ana menuye git*****************
            {
                goto Anamenu;
            }

    break;
case 2:
    printf("\n \n \n \t \t \t \t \t CEKILIS ISTATISLIKLERI\n");
    break;
case 3:
    printf("\n PROGRAMDAN ÇIKNMAK İSTİYOR MUSUNUZ?\n-->[E]vet\n-->[H]ayir\n\a");
    cikissec:
    printf("\n-->");
    scanf("%s",&cikis);
      switch(cikis)
      {
       case 'e':
       case 'E':exit(0);
       break;
       case 'H':
       case 'h':goto Anamenu;
       break;
       default: printf("Tanimsiz deger girisi, E veya H karakter girisi yapin.\n\a"); goto cikissec;
      }
    break;


  }
    }
    return 0;


  }
