#pragma once
#include <stdexcept>

template <typename Tipo>
class FilaSequencial
{
public:
    FilaSequencial()
    {
        m_inicio = 0;
        m_fim = -1;
        m_numElementos = 0;
        m_tamanhoMax = 100;
        m_dados = new int[m_tamanhoMax];
    }

    FilaSequencial(int tamanho)
    {
        m_inicio = 0;
        m_fim = -1;
        m_numElementos = 0;
        m_tamanhoMax = tamanho;
        m_dados = new int[m_tamanhoMax];
    }

    ~FilaSequencial()
    {
        delete [] m_dados;
    }

    bool isVazia()
    {
        return m_numElementos == 0;
    }

    bool isCheia()
    {
        return m_numElementos == m_tamanhoMax;
    }

    int tamanho()
    {
        return m_numElementos;
    }

    Tipo primeiro()
    {
        if (isVazia())
        {
            throw std::range_error("Fila esta vazia, nao possui primeiro elemento.");
        }
        return m_dados[m_inicio];
    }

    bool inserir(Tipo dado)
    {
        if (isCheia())
        {
            return false;
        }
        
        m_fim = (m_fim + 1) % m_tamanhoMax;

        m_dados[m_fim] = dado;
        m_numElementos++;

        return true;
    }

    Tipo remover()
    {
        if (isVazia())
        {
            throw std::range_error("Fila esta vazia, nao tem como remover.");
        }

        Tipo ret = primeiro();

        m_inicio = (m_inicio + 1) % m_tamanhoMax;
        m_numElementos--;

        return ret;
    }

private:
    Tipo    *m_dados;
    int     m_inicio;
    int     m_fim;
    int     m_numElementos; 
    int     m_tamanhoMax;
};
