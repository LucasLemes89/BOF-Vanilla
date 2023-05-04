# BOF-Vanilla
código em c vulnerável a Buffer Overflow - Vanilla case

O código é um exemplo simples de um servidor TCP que é vulnerável a um ataque de buffer overflow. O servidor escuta na porta TCP 5555 e espera conexões de clientes. Quando um cliente se conecta, o servidor lê uma string de tamanho máximo 10 do cliente e a imprime na tela.

Este código contém uma vulnerabilidade de buffer overflow, pois o tamanho do buffer buffer é fixo em 10 bytes, mas não há nenhuma verificação se a quantidade de dados recebida é maior que isso. Com isso, caso o cliente envie mais de 10 bytes, ocorrerá uma sobrescrita de memória, podendo causar comportamentos inesperados ou até mesmo um ataque bem sucedido.

É importante ressaltar que esse tipo de vulnerabilidade é muito comum e deve ser evitada em ambientes reais de produção. Para evitar buffer overflows, é recomendado utilizar funções que verificam a quantidade de dados alocados ou recebidos, como strncpy e snprintf.

Para corrigir esta vulnerabilidade, é necessário verificar o tamanho da entrada do cliente antes de escrevê-la no buffer e garantir que o buffer tenha espaço suficiente para a entrada. Além disso, o uso de funções mais seguras, como fgets(), pode ajudar a evitar vulnerabilidades de buffer overflow.
