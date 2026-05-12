# 💧 Lembrete de Água Automático

Um utilitário leve e eficiente escrito em **C** utilizando a biblioteca **Raylib**. Este programa roda silenciosamente em segundo plano e exibe um alerta visual e sonoro a cada 30 minutos para lembrar o usuário de se hidratar.

## ✨ Funcionalidades

* **0% de Consumo em Standby:** Utiliza chamadas nativas do sistema (`Sleep` no Windows / `sleep` no Linux) para aguardar o tempo determinado sem consumir processamento ou memória de vídeo.
* **Alertas Sonoros Aleatórios:** Sorteia entre diferentes efeitos sonoros (`plin.wav` ou `Fahh.wav`) a cada notificação.
* **Janela Não Intrusiva:** A notificação aparece no canto da tela, sem bordas (`Undecorated`), sempre no topo (`Topmost`), mas permite que o mouse passe através dela (`Mouse Passthrough`) para não atrapalhar o seu trabalho.

---

## 📁 Estrutura do Projeto

Para que o programa funcione corretamente, a estrutura de pastas deve ser mantida da seguinte forma:

```text
lembrete-de-agua/
│
│           
├── LembreteAgua.exe    # Executável compilado (Windows)
├── README.md           # Este arquivo
│
└── src/               
    ├── main.c          # Código-fonte principal
    ├── plin.wav        # Efeito sonoro 1
    └── Fahh.wav        # Efeito sonoro 2
