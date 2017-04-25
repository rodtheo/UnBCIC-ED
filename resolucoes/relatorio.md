= Relatório
Rodrigo Theodoro Rocha <doc@example.com>
:doctype: book
:reproducible:
//:source-highlighter: coderay
:source-highlighter: rouge
:listing-caption: Listing
// Uncomment next line to set page size (default is A4)
//:pdf-page-size: Letter
:math:
:imagesoutdir: generated_images
:imagesdir: images
:stem: latexmath

== Descrição Notação Polonesa

A notação polonesa reversa, refere-se a forma de escrever expressões algébricas na qual a posição relativa dos operadores é após dois operandos (posfixa). Por exemplo, a expressão $A+B*C$, escrita na forma usual (infixa) pode ser reescrita na forma posfixa respeitando-se a precedência dos operadores. Neste caso, a multiplicação precede a operação de adição, na ausência de parênteses que indiquem o contrário. Portanto a expressão A+B&ast;C pode ser interpretada como A+(B&ast;C) e convertida para a forma posfixa através das 4 etapas a seguir:

["lowerroman"]
- A + (B * C) parêntese para obter ênfase;
- A + (BC*) conversão da multiplicação;
- A(BC*)+ conversão da adição;
- ABC*+ forma posfixa

Para a conversão somente é necessário lembrar a ordem de precedência dos operadores e as restrições impostas pelos parênteses na expressão. A ordem de precedência é descrita a seguir:

1. Exponenciação
2. Multiplicação/Divisão
3. Adição/Subtração
