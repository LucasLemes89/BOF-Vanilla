# BOF-Vanilla
código em c vulnerável a Buffer Overflow - Vanilla case

O código é um exemplo simples de um servidor TCP que é vulnerável a um ataque de buffer overflow. O servidor escuta na porta TCP 5555 e espera conexões de clientes. Quando um cliente se conecta, o servidor lê uma string de tamanho máximo 10 do cliente e a imprime na tela.

Este código é vulnerável a um ataque de buffer overflow porque ele usa a função read() para ler dados do cliente em um buffer de tamanho fixo de 10 bytes. Se o cliente enviar uma string maior que 10 bytes, a função read() continuará a escrever dados na memória além do final do buffer, corrompendo a memória do programa e possivelmente levando a um comportamento inesperado ou a uma falha do programa.

Para corrigir esta vulnerabilidade, é necessário verificar o tamanho da entrada do cliente antes de escrevê-la no buffer e garantir que o buffer tenha espaço suficiente para a entrada. Além disso, o uso de funções mais seguras, como fgets(), pode ajudar a evitar vulnerabilidades de buffer overflow.
