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
	Senha* s = (Senha*) malloc(sizeof(Senha)); //ponteiro para guardar uma senha, alocando memoria 
	s->id =  (qtdNormal + qtdPrioridade)+1; 
	s->prioridade = prioridade; 
	if(prioridade){ 
		s->senha = ++qtdPrioridade; 
	}else{ // se não
		s->senha = ++qtdNormal; 
	}
	s->next = NULL;
	printf("\nSENHA: %s%d\nTIPO: %s\n", s->prioridade ? " P" : " N", s->senha, s->prioridade ? " PRIORITARIA" : " NORMAL");
	if(*senha == NULL){ // se a fila for vazia, ele adiciona ela no inicio
		*senha = s; 
	}else{ 
		Senha* aux = *senha; 
		while(aux->next != NULL){ // usamos um loop para percorrer todos realocando todos uma pocisão a cima
			aux = aux->next;
		}
		aux->next = s; 
	}
}

Senha* prioridade(Senha *senhas){
	Senha* s = senhas; // criamos um ponteiro para armazenar temporariamente a fila de senhas
	while (s != NULL) { 
		if (s->prioridade == 1) break; 
		s = s->next; 
	}
	if (s == NULL) return NULL; 
	return s; 
}

Senha* excluirsenha(Senha *senhas, int id){
	Senha* ant = NULL; 
	Senha* s = senhas; 

	while (s != NULL && s->id != id) { // criamos um looping para percorrer as senhas até o final da fila ou encontarar uma com o id que querermos
		ant = s; 
		s = s->next; 
	}
	if(s == NULL){
		return senhas; 
	}
	if (ant == NULL) { // se a senha anterior for NULL quer dizer que o que procuramos está no topo da fila
		senhas = s->next; 
	}else { 
		ant->next = s->next; 
	}
	free(s); // liberamos da memoria o ponteiro que criamos para percorrer as senhas
	return senhas;
}

void chamar(Senha** senhas, SenhasChamadas** senhasChamadas, int *cp){

	if(*senhas == NULL) return; // se a fila de senhas for NULL então a fila está vazia e encerramos a função

	Senha* s; // criamos um ponteiro para senhas
	if(*cp == 2){
		s = *senhas;
		*cp = 0; 
	}else{ 
		Senha* prioridades = prioridade(*senhas); // criamos um pontiro para senhas e inicializamos ele com a função de prioridade
		if(prioridades != NULL){ 
			s = prioridades; // então atrinuimos ela ao ponteiro de senhas que criamos e incrementamos o contador de senha com prioridades chamadas
			*cp = *cp + 1; 
		}else{ 
			s = *senhas; // então chamamos o proximo da fila, que sempre sera o primeiro
		}
	}

	SenhasChamadas* sc = (SenhasChamadas*) malloc(sizeof(SenhasChamadas)); // criamos um ponteiro para as senhas já chamadas e inicializamos alocando memoria 
	Senha *ant = (Senha*) malloc(sizeof(Senha));  // criamos um ponteiro para uma senha e alocamos memoria do tamannho de uma strutura Senha
	ant->id = s->id; 
	ant->prioridade = s->prioridade; 
	ant->senha = s->senha; 
	ant->next = NULL; 
	sc->senha = ant; 
	sc->next = *senhasChamadas; 
	*senhasChamadas = sc; 
	printf("\nSENHA CHAMADA: %s%d\nTIPO: %s\n", s->prioridade ? " P" : " N", s->senha, s->prioridade ? " PRIORITARIA" : " NORMAL");
	*senhas = excluirsenha(*senhas, s->id); 
}


void listarSenhas(Senha *senhas){
   	printf("\n---- SENHAS EM ESPERA ----\n"); 
    Senha* s; 
    printf(" SENHA  |  TIPO\n");  
	for (s = senhas; s != NULL; s = s->next){
		printf("%s%d      %s\n", s->prioridade ? " P" : " N", s->senha, s->prioridade ? " PRIORITARIA" : " NORMAL");
	} 
}


#endif