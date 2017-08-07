/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main()
{
    char c = 0;

    int words = 0; // contagem de palavras

    int lt,cm, pt, num, sep;  // flags atuais de letras (lt), virgula (cm), ponto (pt), numero (num) e separadores (sep, espaço, - , !, ?)

    lt = 0; cm = 0; pt = 0; num = 0; sep = 0;

    int Alt, Acm, Apt, Anum, Asep;  // flags ANTERIORES de letras (lt), virgula (cm), ponto (pt), numero (num) e separadores (sep, espaço, -, :, !,)

    Alt = 0; Acm = 0; Apt = 0; Anum = 0; Asep = 0;


    while (c != '\n')
    {
        scanf("%c", &c);

        //Tratamento da entrada

        //Caso 1: Letras
        if( ((65 <= c && c <= 90) || (97 <= c && c <= 122)) ) {lt = 1;}

        //Caso 2: virgula
        if(c == 44) {cm = 1;}

        //Caso 3: ponto
        if(c == 46){pt = 1;}

        //Caso 4: números
        if(48 <= c && c <= 57){num = 1;}

        //Caso 5: separadores
        if(c == 32 || c == 33 || c == 45 || c == 58){sep = 1;}


        //Significado da entrada

        if(!sep) //executa sempre que nao for um separador
        {
            //Sequencia de letras
            if(lt==1 && Alt==0) {words++;} //Verifica se a letra atual faz parte da palavra atual ou se é nova palavra

            //sequencia de numeros inteiros
            if(num==1 && Anum==0 && Asep==1) {words++;}

            //numeros decimais
            if( num==1 && Asep==0 && Anum==0 && Acm==0 && Apt==0) {words++;}
                //somente atualiza words se esse número nao tiver sido precedido
                //por um separador, número, virgula ou ponto.
                
        }


        //Copio o estado atual no estado passado
        Alt  = lt;
        Acm  = cm;
        Apt  = pt;
        Anum = num;
        Asep = sep;

        //Reseto as flags
        lt = 0; cm = 0; pt = 0; num = 0; sep = 0;

    }

    printf("%d\n", words);

    return 0;
    
}
