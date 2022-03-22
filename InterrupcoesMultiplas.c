


sbit LCD_RS at RC0_bit;
sbit LCD_EN at RC1_bit;
sbit LCD_D4 at RC4_bit;
sbit LCD_D5 at RC5_bit;
sbit LCD_D6 at RC6_bit;
sbit LCD_D7 at RC7_bit;

sbit LCD_RS_Direction at TRISC0_bit;
sbit LCD_EN_Direction at TRISC1_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISC6_bit;
sbit LCD_D7_Direction at TRISC7_bit;


char *texto1="Interrupt1";
char *texto2="interrupt2";

int contador1=0;
int contador2=0;
bit MudancaDisplay;




void interrupt(){
     if(T0IF_bit=1) {
         T0IF_bit=0;
         TMR0=0;
         contador1++;
         if(contador1>500){
                contador1=0;
         }
     }
       if(TMR1IF_bit=1) {
         TMR1IF_bit=0;
         TMR1L=255;
         TMR1H=206;
         contador2++;
         if(contador2>10){
              contador2=0;
              MudancaDisplay=~MudancaDisplay;
         }
     }

}
void main() {
     OPTION_REG=0b10000001;
     GIE_bit=1;
     PEIE_bit=1;
     T0IE_bit=1;
     TMR1IE_bit=1;
     T1CON= 0b00110001;
     
     TMR0=6;
     TMR1L=255;
     TMR1H=205;
     TRISC=0b00001100;
     PORTC=0;
     MudancaDisplay=0;
     
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Cmd(_LCD_CLEAR);
     
     while(1){
      if(MudancaDisplay==0){
             Lcd_Out(1,2,texto1);
      
      }
      else{
         Lcd_Out(1,2,texto2);
      }
     
     
     
     }
     
}