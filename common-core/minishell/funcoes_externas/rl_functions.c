/*
 * Aqui vamos aprender na prática e teoria sobre as funções:
 * --------------------------------------------------------------------------------------
 * | readline		| char *readline(const char *prompt)				|
 * | rl_clear_history	| void rl_clear_history(void)					|
 * | rl_on_new_line	| void rl_on_new_line(void)					|
 * | rl_replace_line	| void rl_replace_line (const char *text, int clear_undo)	|
 * | rl_redisplay	| void rl_redisplay (void)					|
 * | add_history	| void add_history(const char *string)				|
 * --------------------------------------------------------------------------------------
 *
 *
 *
 * !!! Necessário compilação a flag "-lreadline". !!!
 * Ambas ultilizam as bibliotecas "readline/readline.h" e "readline/history.h".
*/

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char	*input;
	char	*rev_input;
	int		i;
	int		input_len;

	printf("Bem-vindo ao programa de exemplo readline!\n");
	printf("Digite 'sair' para sair.\n");

	while (1)
	{
		// Abre um prompt para ler o que o usuário digitar
		input = readline("\nDigite uma sequência de caracteres: ");

		// Adiciona o input em um histórico de comandos
		add_history(input);

		// Verifica se o usuário deseja sair. Caso sim, libera a memória e interrompe o loop
		if (strcmp(input, "sair") == 0)
		{
			free(input);
			break ;
		}

		// Calcula o tamanho da string de entrada
		input_len = strlen(input);
		rev_input = (char *) malloc((input_len + 1) * sizeof(char));

		// Inverte a sequência de caracteres
		i = -1;
		while (++i < input_len)
			rev_input[i] = input[input_len - i - 1];
		rev_input[input_len] = '\0';
		
		// Troca a linha de entrada pela string invertida
		rl_on_new_line();
		rl_replace_line(rev_input, 0);
		rl_redisplay();

		// Libera memória
		free(rev_input);
		free(input);
	}

	// Limpa o histórico de inputs
	rl_clear_history();
	printf("\nPrograma encerrado.\n");

	return (0);
}
/*
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// UM POUCO SOBRE AS FUNÇÕES ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

1. READLINE

A função 'readline' é frequentemente usada em programas interativos para ler uma linha de entrada
do usuário de maneira eficiente e conveniente. Ela não faz parte da biblioteca padrão C, mas sim
da biblioteca GNU Readline, que é uma biblioteca de software que facilita a edição de linhas de
comando e a manipulação de histórico.

-> Sintaxe

char	*readline(const char *prompt);

-> Parâmetros

*prompt: Uma string que será exibida como prompt para o usuário. Pode ser NULL ou uma string
vazia se nenhum prompt for necessário.

-> Retorno

*Linha de Entrada: Um ponteiro para a string que contém a linha lida. A string é alocada
dinamicamente e deve ser liberada pelo chamador usando free.
*NULL: Se ocorrer um erro ou se o final de arquivo (EOF) for encontrado.

-> Descrição

A função 'readline' lê uma linha de entrada do terminal. Ela exibe o prompt especificado,
se houver, e permite ao usuário editar a linha usando comandos de edição de linha familiares,
como mover o cursor, apagar caracteres, etc. A linha lida inclui todo o texto inserido pelo
usuário, mas não inclui o caractere de nova linha.

-> Pontos Importantes

*Alocação de Memória: A string retornada por 'readline' é alocada dinamicamente e deve ser
liberada usando 'free' para evitar vazamentos de memória.
*Dependências: A biblioteca GNU Readline deve estar instalada e vinculada ao seu programa. Em
muitos sistemas Unix, isso pode ser feito com '-lreadline' na linha de comando do compilador.

-> Conclusão

A função 'readline' da biblioteca GNU Readline é uma ferramenta poderosa para programas
interativos que exigem entrada de linha de comando do usuário. Com funcionalidades como edição de
linha, suporte a histórico e personalização, ela pode melhorar significativamente a experiência
do usuário. No entanto, como não faz parte da biblioteca padrão C, é necessário garantir que a
biblioteca Readline esteja disponível no ambiente de desenvolvimento e que seu programa esteja
corretamente vinculado a ela.

/////////////////////////////////////////////////////////////////////////////////////////////////

2. RL_CLEAR_HISTORY

A função 'rl_clear_history' faz parte da biblioteca GNU Readline e é utilizada para limpar o
histórico de comandos armazenados durante a execução de um programa que utiliza esta biblioteca.
Isso é útil para redefinir o histórico e remover todos os comandos previamente armazenados.

-> Sintaxe

void	rl_clear_history(void);

-> Parâmetros

A função 'rl_clear_history' não recebe parâmetros.

-> Retorno

A função 'rl_clear_history' não retorna nenhum valor.

-> Descrição

A função 'rl_clear_history' limpa o histórico de comandos, removendo todas as entradas que foram
adicionadas anteriormente. Após chamar essa função, o histórico fica vazio e nenhum comando
anterior estará disponível para recuperação através da navegação no histórico.

-> Pontos Importantes

*Histórico Global: A função 'rl_clear_history' afeta o histórico global gerido pela biblioteca
Readline. Isso significa que todos os comandos armazenados até o momento serão removidos.
*Gerenciamento de Memória: As entradas de históricos são gerenciadas pela biblioteca Readline, e
a função 'rl_clear_history' cuida da liberação de memória associada a essas entradas.

-> Conclusão

A função 'rl_clear_history' é uma ferramenta útil da biblioteca GNU Readline para limpar o
histórico de comandos de um programa. Ela permite que os desenvolvedores gerenciem e redefinam o
histórico de comandos conforme necessário, proporcionando maior controle sobre a interação do
usuário com o histórico de comandos.

/////////////////////////////////////////////////////////////////////////////////////////////////

3. RL_ON_NEW_LINE

A função 'rl_on_new_line' faz parte da biblioteca GNU Readline e é utilizada para informar ao
readline que o cursor foi movido para uma nova linha. Isso é útil em situações onde você deseja
redefinir o estado de edição da linha de comando, especialmente após operações que afetam a linha
de comando atual.

-> Sintaxe

void	rl_on_new_line(void);

-> Parâmetros

A função 'rl_on_new_line' não recebe parâmetros.

-> Retorno

A função 'rl_on_new_line' não retorna nenhum valor.

-> Descrição

A função 'rl_on_new_line' informa à biblioteca Readline que o cursos foi movido para uma nova
linha. Isso é geralmente necessário quando a linha de comando atual foi alterada diretamente (por
exemplo, através de uma chamada a 'rl_replace_line') e você precisa garantir que a próxima vez
que o Readline atualizar a linha, ele considere isso como uma nova linha.

-> Aplicações Comuns

*Atualização de Linha: Quando você precisa atualizar ou substituir a linha de comando atual de
maneira limpa.
*Reescrever o Prompt: Para casos onde o prompt e a linha de comando precisam ser reescritos após
operações que afetam a exibição da linha de comando.
*Integração com Outros Sistemas de Entrada/Saída: Em programas complexos onde a linha de comando
precisa ser sincronizada com outras formas de entrada e saída.

-> Pontos Importantes

*Uso com Outras Funções Readline: 'rl_on_new_line' é frequentemente usada em conjunto com outras
funções da biblioteca Readline, como 'rl_replace_line' e 'rl_redisplay', para garantir que a
linha de comando seja atualizada corretamente.
*Não Redesenha Automaticamente: A função 'rl_on_new_line' não redesenha a linha de comando por si
só; ela apenas sinaliza ao readline que o cursor está em uma nova linha. Para redesenhar a linha
de comando, você geralmente usará 'rl_redisplay'.

-> Conclusão

A função 'rl_on_new_line' da biblioteca GNU Readline é uma ferramenta importante para gerenciar a
atualização da linha de comando em aplicativos interativos. Ela permite que os desenvolvedores
sinalizem ao readline que o cursor foi movido para uma nova linha, garantindo que futuras
atualizações da linha de comando considerem esse estado. Isso é especialmente útil em cenários
onde a linha de comando precisa ser manipulada dinamicamente, proporcionando uma interação suave
e consistente para o usuário.

/////////////////////////////////////////////////////////////////////////////////////////////////

4. RL_REPLACE_LINE

A função 'rl_replace_line' faz parte da biblioteca GNU Readline e é utilizada para substituir o
conteúdo da linha de comando atual com uma nova string. Essa função é útil quando você deseja
programaticamente alterar a linha de comando que o usuário está editando.

-> Sintaxe

void	rl_replace_line(const char *text, int clear_undo);

-> Parâmetros

*text: Uma string que substituirá o conteúdo atual da lnha de comando.
*clear_undo: Um inteiro que indica se o histórico de desfazer deve ser limpo ('1' para limpar,
'0' para manter).

-> Retorno

A função 'rl_replace_line' não retorna nenhum valor.

-> Descrição

A função 'rl_replace_line' substitui o texto da linha de comando atual com o conteúdo fornecido
em 'text'. O parâmetro 'clear_undo' determina se o histórico de operações de desfazer deve ser
limpo ou não. Quando 'clear_undo' é definido como '1', qualquer histórico de desfazer para a
linha de comando atual será removido, o que significa que o usuário não poderá desfazer a
substituição. Se definido como '0', o histórico de desfazer será preservado.

-> Aplicação Comuns

*Edição Programática: Quando um programa deseja modificar a linha de comando atual que o usuário
está editando com base em algum evento ou condição.
*Sugestão de Comando: Para substituir automaticamente a linha de comando com sugestões ou
correções baseadas na entrada do usuário.
*Macros e Atalhos: Implementação de macros ou atalhos que modificam a linha de camando atual.

-> Pontos Importantes

*Redesenho Necessário: Após chamar 'rl_replace_line', a linha de comando não é automaticamente
redesenhada. Você deve chamar 'rl_redisplay' para atualizar a exibição.
*Histórico de Desfazer: O parâmetro 'clear_undo' controla se as operações de desfazer são
mantidas ou limpas. Escolha '1' para limpar o histórico de desfazer e '0' para preservá-lo.
*Memória: A string fornecida em 'text' deve estar disponível na memória pelo menos até a próxima
vez que a linha de comando for modificada.

-> Conclusão

A função 'rl_replace_line' da biblioteca GNU Readline é uma ferramenta poderosa para substituir
programaticamente o conteúdo da linha de comando atual. Ela oferece flexibilidade para
desenvolvedores que precisam modificar dinamicamente a linha de comando com base em eventos
específicos ou lógica de aplicação, melhorando a interação do usuário com a linha de comando.

/////////////////////////////////////////////////////////////////////////////////////////////////

5. RL_REDISPLAY

A função 'rl_redisplay' faz parte da biblioteca GNU Readline e é utilizada para atualizar a
exibição da linha de comando. Isso é útil quando a linha de comando foi modificada
programaticamente e você deseja refletir essas mudanças na tela.

-> Sintaxe

void	rl_redisplay(void);

-> Parâmetros

A função 'rl_redisplay' não recebe parâmetros.

-> Retorno

A função 'rl_redisplay' não retorna nenhum valor.

-> Descrição

A função 'rl_redisplay' redesenha a linha de comando atual no terminal. Isso é útil após fazer
alterações programáticas na linha de comando, como com 'rl_replace_line', para garantir que a
exibição no terminal corresponda ao estado atual da linha de comando.

-> Aplicações Comuns

*Atualização da Linha de Comando: Sempre que a linha de comando é alterada programaticamente e
você deseja que essa alteração seja refletida imediatamente na interface do usuário.
*Interface Responsiva: Para garantir que a exibição da linha de comando esteja sincronizada com o
estado interno do programa, proporcionando uma interface de usuário mais responsiva e intuitiva.
*Correções e Sugestões Dinâmicas: Em cenários onde a linha de comando precisa ser corrigida ou
complementada dinamicamente com base na entrada do usuário.

-> Pontos Importantes

*Eficácia Imediata: A função 'rl_redisplay' redesenha imediatamente a linha de comando no
terminal, garantindo que quaisquer alterações feitas sejam visíveis ao usuário.
*Uso com Outras Funções Readline: Frequentemente usada em conjunto com outras funções de
Readline, como 'rl_replace_line', para manter a interface do usuário sincronizada com o estado
interno da linha de comando.
*Interatividade: Ideal para programas interativos onde a linha de comando pode mudar em resposta
a eventos ou ações do usuário, assegurando que essas mudanças sejam imediatamente visíveis.

-> Conclusão

A função 'rl_redisplay' da biblioteca GNU Readline é uma ferramenta essencial para atualizar a
exibição da linha de comando no terminal. Ela garante que quaisquer alterações feitas
programaticamente na lnha de comando sejam imediatamente refletidas na interface do usuário,
melhorando a interação e a responsividade do programa.

/////////////////////////////////////////////////////////////////////////////////////////////////

6. ADD_HISTORY

A função 'add_history' faz parte da biblioteca GNU Readline e é ultilizada para adicionar uma
nova entrada ao histórico de comandos. Isso permite que os comandos inseridos pelo usuário sejam
armazenados e recuperados posteriormente, facilitando a navegação e repetição de comandos
anteriores.

-> Sintaxe

void	add_history(const char *string);

-> Parâmetros

*string: Um ponteiro para a string que representa o comando a ser adicionado ao histórico.

-> Retorno

A função 'add_history' não retorna nenhum valor.

-> Descrição

A função 'add_history' adiciona a string fornecida ao histórico de comandos mantido pela
biblioteca Readline. Isso é útil para armazenar comandos inseridos pelo usuário, permitindo que
eles sejam acessados e reutilizados posteriormente usando as teclas de navegação do histórico
(geralmente as teclas de seta para cima e para baixo).

-> Aplicações Comuns

*Armazenamento de Comandos do Usuário: Para armazenar comandos digitados pelo usuário, permitindo
recuperação e reutilização.
*Sessões Interativas: Em programas interativos, onde o histórico de comandos pode melhorar a
usabilidade ao permitir que o usuário acesse comandos anteriores facilmente.
*Desenvolvimento de Shells: Em shells personalizadas ou interfaces de linha de comando, onde o
histórico de comandos é uma funcionalidade esperada.

-> Pontos Importantes

*Persistência do Histórico: Por padrão, o histórico de comandos existe apenas na memória durante
a execução do programa. Para persistir o histórico entre sessões, você pode pesquisar funções como
'write_history' e 'read_history'.
*Memória: As entradas de histórico são armazenadas na memória. Certifique-se de gerenciar a
memória adequadamente para evitar vazamentos, especialmente se você estiver manipulando grandes
quantidades de histórico.
*Duplicação de Comandos: Dependendo das configurações da Readline, comandos duplicados podem ser
armazenados no histórico. Você pode configurar o comportamento para evitar duplicatas se
desejado.

-> Conclusão

A função 'add_history' da bilioteca GNU Readline é uma ferramenta essencial para gerenciar o
histórico de comandos em aplicativos de linha de comando interativos. Ela permite que os
desenvolvedores armazenem e recuperem comandos de maneira eficiente, melhorando a experiência do
usuário e facilitando a repetição de comandos anteriores.

/////////////////////////////////////////////////////////////////////////////////////////////////
*/
