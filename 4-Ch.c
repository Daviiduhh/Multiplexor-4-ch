#INCLUDE <16F887.H>
#DEVICE ADC=8 
#USE DELAY(CLOCK=4000000)
#FUSES INTRC_IO,NOWDT,NOPUT,NOMCLR,NOPROTECT,NOCPD,NOBROWNOUT
#FUSES NOIESO,NOFCMEN,NOLVP,NODEBUG,NOWRT,BORV21

#USE FAST_IO(A)
#USE FAST_IO(B)
#USE FAST_IO(C)
#USE FAST_IO(D)

#INCLUDE <LCD1.C>
INT D,X;
FLOAT V,K;

VOID MAIN ()
{
SET_TRIS_A(0XFF);
SET_TRIS_C(0XFF);
LCD_INIT();
SETUP_ADC(ADC_CLOCK_INTERNAL);
SETUP_ADC_PORTS(sAN0|sAN1|sAN2|sAN3); 

   WHILE (TRUE)
   {
   X=INPUT_C();
   X=X&0X03;
   SET_ADC_CHANNEL(X);
   D=READ_ADC();
   K=0.0196;
   V=D*K;
   LCD_GOTOXY(1,1);
   PRINTF(LCD_PUTC, "CH=%u DIGITAL=%u       \nANALOGICO = %1.3g      ",X,D,V);
   }
}
