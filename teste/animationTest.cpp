# include  <thread> 
# include  <iostream>

int  main () {
	 // Exemplo de animação 
	for ( int i { 0 }; i < 50 ; ++ i) {
		 // Este código pausa a `duração` milissegundos entre os quadros. 
		// Converte fps em milissegundos. 
		int fps { 2 };
		std :: chrono :: milliseconds duration{ 1000 / fps};
		std :: this_thread :: sleep_for (duration);
		std :: cout << " Esta frase será impressa na saída padrão aproximadamente " << fps << " vezes por segundo. \ n " ;
	}
	return  0 ;
}