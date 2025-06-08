# Relatório Comparativo: Comunicação com e sem Threads

## 1. Introdução

Este relatório compara duas abordagens para comunicação entre tarefas em C:  
- **Sem uso de threads:** Comunicação entre processos distintos, utilizando arquivos ou memória compartilhada.
- **Com uso de threads:** Comunicação entre threads de um mesmo processo, utilizando variáveis globais e mecanismos de sincronização (mutex e condição).

---

## 2. Comunicação Sem Threads (Entre Processos)

### Funcionamento
- Cada programa (escritor e leitor) é um processo independente.
- A comunicação ocorre por meio de arquivos ou segmentos de memória compartilhada do sistema operacional.
- É necessário sincronizar o acesso ao recurso compartilhado (arquivo ou memória) para evitar condições de corrida.

### Vantagens
- **Isolamento:** Falhas em um processo não afetam o outro.
- **Paralelismo real:** Pode ser executado em diferentes núcleos da CPU.
- **Escalabilidade:** Facilita a distribuição em diferentes máquinas (com adaptações).

### Desvantagens
- **Complexidade:** Gerenciar memória compartilhada, arquivos e sincronização é mais difícil.
- **Desempenho:** Comunicação entre processos é mais lenta devido ao overhead do sistema operacional.
- **Consumo de recursos:** Cada processo consome mais memória e recursos do sistema.

---

## 3. Comunicação Com Threads

### Funcionamento
- Escritor e leitor são funções executadas como threads dentro do mesmo processo.
- Compartilham variáveis globais diretamente.
- Sincronização é feita com mutexes e variáveis de condição.

### Vantagens
- **Simplicidade:** Compartilhamento de dados é direto, sem necessidade de mecanismos externos.
- **Desempenho:** Comunicação é mais rápida, pois ocorre na mesma área de memória.
- **Baixo consumo de recursos:** Threads são mais leves que processos.

### Desvantagens
- **Menor isolamento:** Erros em uma thread podem afetar todo o processo.
- **Concorrência:** É necessário cuidado com sincronização para evitar condições de corrida.
- **Escalabilidade limitada:** Todas as threads compartilham o mesmo espaço de endereçamento.

---

## 4. Comparação de Complexidade

| Critério                | Sem Threads (Processos) | Com Threads           |
|-------------------------|------------------------|-----------------------|
| Compartilhamento de dados | Difícil (memória/arquivo) | Fácil (variável global) |
| Sincronização           | IPC, sinais, arquivos  | Mutex, condição       |
| Isolamento              | Alto                   | Baixo                 |
| Debug                   | Mais fácil             | Mais difícil          |

---

## 5. Comparação de Desempenho

- **Tempo de execução:**  
  - Threads geralmente apresentam menor tempo de comunicação, pois não há troca de contexto entre processos nem overhead de IPC.
- **Consumo de recursos:**  
  - Threads consomem menos memória e recursos do sistema.

---

## 6. Conclusão

- **Threads** são recomendadas para comunicação rápida e simples dentro do mesmo processo, quando o isolamento não é crítico.
- **Processos** são preferíveis quando é necessário isolamento, robustez e potencial escalabilidade entre diferentes máquinas ou ambientes.

---