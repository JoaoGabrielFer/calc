# Uso

### Comando no terminal:
    ./calc++ /f <file> 

    ./calc++ /e <expressão>

obs: é necessãrio usar aspas (") na expressão caso ela contenha espaços.

    ./calc++ /e "12 + 4 - 5 * 3"

## Sintáxe no arquivo

Nesta linguagem pode ser usado ou não o ';'

Então, tanto assim;

    12+4-5*3
    1+4
    2(5-2)

quanto assim;

    12+4-5*3;
    1+4;
    2(5-2);

quanto assim:

    12+4-5*3; 1+4; 2(5-2);

está correto. 

## Sintáxe inline

Entretanto, no terminal, só pode usar o ';', caso queira executar mais de uma linha de código.

    ./calc++ /e "12+4-5*3; 1+4; 2(5-2);"
