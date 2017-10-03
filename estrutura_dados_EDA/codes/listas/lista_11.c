#include "lista_11.h"


// UMA PRIMITIVA -- generica a qualquer momento
noh_tipo * cria_no(void)
{
 noh_tipo  *new_node;
 new_node = (noh_tipo *) malloc(sizeof(noh_tipo)) ;

 if( new_node == NULL)
	{
		printf("\n Erro de alocacao .... falta memoria!");
		getchar();
		exit(1);
	}
	return(new_node);
}

// IMPRIME A LISTA
// vem o endereco original
void imp_lista(noh_tipo *L)
{ 
  puts("\n IMPRIME LISTA: \n ============================");
  int i=1;
 // printf("\n %d o. Noh:::  NOME: %s", i , ( L -> nome));
  do {
	  printf("\n %do. Noh  NOME: %s", i , ( L -> pt_nome));
	  L = L -> next;
      i++;
	} while( L != NULL );
	//while(L -> next != NULL);
	
	return;
}

// insere no inicio
void ins_inic_lista(char *pt_DADO, noh_tipo ** head) 
{
    noh_tipo * new_node;
    new_node = (noh_tipo *) malloc(sizeof(noh_tipo));

    //new_node-> x_nome = val;
    new_node  -> pt_nome = pt_DADO;
    new_node -> next = (*head);// para o lugar onde head estava
    (*head) = new_node ;
}

// insere DADO x_nome na lista
int ins_fim_lista(char *pt_DADO, noh_tipo ** L)
 { // insere ao final da lista

    if( (*L) == NULL ) // caso L nao esteja enderecado a lugar algum
    {
		noh_tipo * novo_no = cria_no ();
		//se lista vazia ... esta vai comecar em ..
		(*L) = novo_no;
		//printf("CONTEUDO de L:  %p\n" , *L);
		//strcpy( novo_no  -> nome , x_nome);
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente o ultimo */
		return 11;
	}	
    else
    {	
    	noh_tipo * novo_no , * aux ;
	    aux = (*L); // inicio da lista
		for( ; aux -> next != NULL ; )
			aux = aux -> next ;
		
		novo_no = cria_no ();   /* CRIA ==> ALOCA */
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente como ultimo */
		aux -> next = novo_no; // atualiza o ultimo em L 
        // novo_no e o ultimo nao perde L
		return 22;
	}
}	
// insere SIMPLIFICADO sem os codigos de retorno
void ins_fim_lista_2(char *pt_DADO,  noh_tipo **L )
 {
   /* vai ser inserido no final da lista */
  if( (*L) == NULL ) // caso L nao esteja enderecado a lugar algum
    {
		noh_tipo * novo_no = cria_no ();
		//se lista vazia ... esta vai comecar em ..
		(*L) = novo_no;
		//strcpy( novo_no  -> nome , x_nome);
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente o ultimo */
		return ;
	}	
    else
    {	
    	noh_tipo * novo_no , * aux ;
	    aux = (*L); // inicio da lista
		for( ; aux -> next != NULL ; )
			aux = aux -> next ;
		
		novo_no = cria_no ();   /* CRIA ==> ALOCA */
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente o ultimo */
		aux -> next = novo_no; // modifica em L 
        // novo_no e o ultimo nao perde L
		return ;
	}
}

// erradp
int is_empty( noh_tipo *L )
	{
		return( L->next == NULL );
	}

/* se eh o ultimo */
int is_last( noh_tipo *L )
{
	return( L->next == NULL );
}

void destroi_lista( noh_tipo **L )
  {
   if( (*L) != NULL )
  	 { int i=1;
  	   noh_tipo  * aux , *prox;
  	   aux =(*L);
	  	  while( aux -> next != NULL ) 
	  	  {
		  	prox = aux -> next;
		  	//free( aux ->  pt_nome );  NAO .....
		  	free(aux); // AQUI LIBERA TUDO 
		  	aux = prox;
		  	//puts(".");
	      	i++;
		  } ;
		      
       free( aux ); // PARA O ULTIMO NO
       printf("\n Total de nosh liberados: %d ", i );
       printf("\n LISTA LIBERADA OK\n " );

       return;
       }

     else
     {
        printf("\n LISTA VAZIA ... NADA a LIBERAR \n" );
        return;
     }
    
  }


// 
int comprimento_lista( noh_tipo **L )
  {
   if( (*L) == NULL )
   return 0;
  
    int i=1; // UM NO
  	   noh_tipo  * aux , *prox;
  	   aux =(*L);
	  	  while( aux -> next != NULL ) 
	  	  {
		  	prox = aux -> next;
		  	aux = prox;
		  	//puts(".");
	      	i++;
		  } ;
		      
     // da para fazer sem *prox  
       //printf("\n Comprimento da lista: %d ", i );
  
       return i;
         
  }


bool exclui_n_esimo_lista( int n, noh_tipo **L )
  {
   if( n > comprimento_lista( L ) || n < 1)
   {
	  printf("\n Erro na exclusao .... posicao INVALIDA!");
	  getchar();
	  return false;
	}
	
    int i=1; // UM NO
  	noh_tipo  * corrente , *anterior;
  	corrente = anterior = (*L);

	if( n == 1) // caso do 1o. da lista
   	{
	  printf("\n NOH: %d => EXCLUINDO NOME: %s", i, ( corrente -> pt_nome));
      (*L) = corrente -> next;
      free(corrente);
      return true;
	}
	// OS DEMAIS ... CREIO QUE PODE SER MELHORADO
    while( i < n ) // avancar ate o no em questao
	 {
	   anterior = corrente;
	   corrente = corrente -> next ; // avanca
	    i++;
	 } ;
		      
    anterior -> next = corrente -> next ;
	printf("\n NOH: %d => EXCLUINDO NOME: %s", i, ( corrente -> pt_nome));
    
    free(corrente);
    return true;
         
  }

 // construa o insercao na N-esima posicao .... 

/******* fim ******/