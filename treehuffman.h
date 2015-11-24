#ifndef TREEHUFFMAN_H
#define TREEHUFFMAN_H
// Essa classe é como uma fila, usa o vetor e ordena ...onde os dois menores são uma sub-árvore e depois voltamos a repetir o processo.
#include <QVector>
#include <algorithm>
#include "nodes.h"
#include"treatmentheader.h"
#include <QHash>


class TreeHuffman {

    QVector<Nodes> BagHuffman; // HAHAHAA a bolsa de huffman terá um conjunto de nodes

    QHash <char , QString > huffmanRepresentationArray; // representação ex: A:111010

    Nodes root;

    QByteArray treerepresetation;

public:

    /*O que segue abaixo sao assinaturas de funçoes
     * retorno_ Nome_ o que recebe*/

    /*Todos essas variáveis são globais :)*/

    TreeHuffman();

    void addNodes(Nodes newNodes);

    int compare(Nodes node01, Nodes node02);

    void ordena(); //A função não recebe nada porque ela já recebe da classe o que ela precisa, no caso, os vectores

    void Teste();

    Nodes *getRoot();

    void printTree(Nodes *nodes, int level=0);

    void BuildHuffman(); // HAHAHA A construção da árvore

    void BuildCodification(Nodes *root, long int level=1); //Codificação da árvore

    void TreeHuffamanRepresetation(Nodes *root);

    QString getHuffmanRepresetation(char position);

    QByteArray Sequency(Nodes *root);// classe para guardar a codificação completa

    int TrashCalcutalion(TreatmentHeader tre);

    QByteArray Header(QString path,int Trash);

    QByteArray bitToByte(QBitArray bits);

    QByteArray getTreeRepresetation();
};

#endif // TREEHUFFMAN_H
