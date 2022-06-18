#ifndef GERADOR_H_INCLUDED
#define GERADOR_H_INCLUDED

typedef struct Senha Senha;
struct Senha{ 
	int id;
	int senha; 
	int prioridade;  
	Senha *next; 
};

typedef struct SenhasChamadas SenhasChamadas;
struct SenhasChamadas{ 
	Senha* senha; 
	SenhasChamadas *next; 
};

typedef struct senhasCanceladas senhasCanceladas;
struct senhasCanceladas{ 
	Senha* senha; 
	senhasCanceladas *next; 
};

Senha* inicializaSenha(){
	return NULL;
}

SenhasChamadas* inicializaSenhasChamadas(){
	return NULL;
}


void gerarSenha(Senha **senha, int qtdNormal, int qtdPrioridade, int prioridade){
	sleep(1);
	Senha* s = (Senha*) malloc(sizeof(Senha)); //pontiero para guardar uma senha, alocando menemoria do tamano de uma strutura senha e convertendo para a senha
	s->id =  (qtdNormal + qtdPrioridade)+1; // atribuindo um id para a senha, ela é a soma de todas as senhas +1 pois a primeiro seria 0 caso não tivesse isso
	s->prioridade = prioridade; //atribuindo a prioridade a senha
	if(prioridade){ // caso tenha prioridade
		s->senha = ++qtdPrioridade; //a senha é o próximo numero da sequencia de senhas prioritarias
	}else{ // se não
		s->senha = ++qtdNormal; // a senha é a próximo número da seguência de senhas normais
	}
	s->next = NULL; // esse ponteiro deve apontar para o NULL pois ele deve ser adicionado em ultimo lugar na fila
	printf("\nSENHA: %s%d\nTIPO: %s\n", s->prioridade ? " P" : " N", s->senha, s->prioridade ? " PRIORITARIA" : " NORMAL");
	if(*senha == NULL){ // se a fila for vazia
		*senha = s; // ele adiciona ela no inicio
	}else{ // se não
		Senha* aux = *senha; // cria um ponteiro auxiliar para senha
		while(aux->next != NULL){ // usamos um loop para percorrer todos realocando todos uma pocisão a cima
			aux = aux->next;
		}// ao sair do looping pegaremos o ultimo lugar
		aux->next = s; //então apontamos ele para a nova senha assim colocando ela no final da fila
	}
}

//função para verificar se tem alguma senha com prioridade na fila
//	parementros
//	Senha* senhas, um ponteiro para uma fila de senhas
Senha* prioridade(Senha *senhas){
	Senha* s = senhas; // criamos um ponteiro para armazenar temporariamente a fila de senhas
	while (s != NULL) { // fazemos um loop até chegar no fim da fila
		if (s->prioridade == 1) break; // caso encontre algum com prioridade então quebre o looping
		s = s->next; //se não chame o proximo da fila
	}
	if (s == NULL) return NULL; // se a váriavel s for NULL quer dizer que não tem prioridades na fila ou ela é vazia então retornamos NULL
	return s; // se não retornamos a senha com prioridade encontrada
}

/*
função para excluir a senha
paramentros
Senha* senha, ponteiro para a fila de senhas
int id, o id da senha a ser removido
*/
/*
   PARA FIGURAS DESSA FUNÇÃO OLHAR A PAGINA 5 DO PDF QUE TEM NO INICIO DESTE DOCUMENTO
*/
Senha* excluirsenha(Senha *senhas, int id){
	Senha* ant = NULL; // criamos um ponteiro para a senha anterior
	Senha* s = senhas; // criams um ponteiro para percorrer a fila de senhas

	while (s != NULL && s->id != id) { // criamos um looping para percorrer as senhas até o final da fila ou encontarar uma com o id que querermos
		ant = s; // salvamos o anterior
		s = s->next; // chamamos o proximo da fila que sera vailiado no loopning se ele é NULL ou contem o id que queromos
	}
	if(s == NULL){// se a senha for NULL quer dizer que chegamos até o final e não achamos o item
		return senhas; // então retornamos a fila de senha como ela está
	}
	if (ant == NULL) { // se a senha anterior for NULL quer dizer que o que procuramos está no topo da fila
		senhas = s->next; //então removemos ela do topo alterando a priemira posição da fila para o proximo da fila
	}else { // se não quer dizer que o item que procuramos esta no meio da fila
		ant->next = s->next; // então pedimos para que o anterior a posição que queremos remover pula o proximo da fila apontando para o proximo do proximo
	}
	free(s); // liberamos da memoria o ponteiro que criamos para percorrer as senhas
	return senhas; // retormanos a nova fila de senha
}

/*
função para chamar as senhas
paramentros
Senha** senhas, pontieiro para um ponteiro de uma fila de senhas
SenhasChamadas** senhasChamadas, ponteiro para um ponteiro de fila de senhas que já foram chamadas
int* cp, ponteiro para um contador de senhas prioritarias
*/
void chamar(Senha** senhas, SenhasChamadas** senhasChamadas, int *cp){

	if(*senhas == NULL) return; // se a fila de senhas for NULL então a fila está vazia e encerramos a função

	Senha* s; // criamos um ponteiro para senhas
	if(*cp == 2){ // se já foi chamada duas senhas prioritárias
		s = *senhas; // então chamar o proximo da fila, que sempre sera o primeiro
		*cp = 0; // zerar o contador de senhas prioritários chamadas
	}else{ // se não
		Senha* prioridades = prioridade(*senhas); // criamos um pontiro para senhas e inicializamos ele com a função de prioridade que pode retornar NULL caso não tenha prioridade ou retornar um ponteiro para a senha que tenha prioridade
		if(prioridades != NULL){ // se não for NULL quer dizer que foi encontrado uma senha com prioridade
			s = prioridades; // então atrinuimos ela ao ponteiro de senhas que criamos
			*cp = *cp + 1; // e incrementamos o contador de senha com prioridades chamadas
		}else{ // se não quer dizer que não foi encontrada senha com prioridade
			s = *senhas; // então chamamos o proximo da fila, que sempre sera o primeiro
		}
	}

	SenhasChamadas* sc = (SenhasChamadas*) malloc(sizeof(SenhasChamadas)); // criamos um ponteiro para as senhas já chamadas e inicializamos alocando memoria do tamanho de uma strutura de SenhasChamadas
	Senha *ant = (Senha*) malloc(sizeof(Senha));  // criamos um ponteiro para uma senha e alocamos memoria do tamannho de uma strutura Senha
	ant->id = s->id; // preenchemos ela com o id da senha que foi selecionada para ser chamada
	ant->prioridade = s->prioridade; // fazemos o mesmo com a priordade
	ant->senha = s->senha; // e é claro com a senha, que é o "importante"
	ant->next = NULL; // podemos apontar para NULL pois essa senha não está mas na fila de senahs a serem chamadas
	sc->senha = ant; // atribuimos o ponteiro criado acima para a fila de senhas chamadas
	sc->next = *senhasChamadas; // e apontamos para a ultima senha chamada, colocando no topo
	*senhasChamadas = sc; // e atribuimos o a nova senha chamada para a fila de senhas chamadas
	printf("SENHA CHAMADA: % %s\nTIPO: %s\n", s->prioridade ? " P" : " N", s->senha, s->prioridade ? " PRIORITARIA" : " NORMAL");
	*senhas = excluirsenha(*senhas, s->id); // excluimos a senha chamada da fila de es
}



#endif