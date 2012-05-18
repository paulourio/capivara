Capivara
==========

Capivara é um web server em C, feito como *trabalho de faculdade*.  Não é 
um aplicativo estável e, portanto, não deve ser utilizado para aplicações 
reais pois não há nenhuma garantia.

Há uma implementação mínima do protocolo HTTP/1.0, encaminhando cada
cabeçalho receido para 
manipuladores (apps hooks) manipuladores de *hosts* registrados.

Dependências
------------

 * clang
 * mysql
 * valgrind

Execução
--------

```
make
```


Diretórios
----------

 * `capivara`: Implementação do web server.

 * `exemplo`: É uma app no formato Model-View-Controller (MVC), que
 manipula cabeçalhos com host www.exemplo.com:8080


Observação
----------

Apesar de ser implementado com a IDE Eclipse, o sistema de build não é
integrado à IDE.


Objetivo
--------

Integrar o projeto em git com o heroku.

