# Atividade 2 - Temporizador de um Disparo (One Shot)

**Desenvolvido por:** Letícia Gonçalves Souza  

Este projeto foi desenvolvido como parte do programa **EmbarcaTech**, com o objetivo de aplicar conceitos de **temporização de um disparo (One Shot)**, **controle de LEDs** e **interação com botões**. A atividade visa consolidar o entendimento prático desses conceitos através da implementação de funcionalidades interativas em um ambiente controlado.

---

## Sobre o Projeto

O projeto consiste em um sistema de temporização que utiliza o **Raspberry Pi Pico W** para acionar LEDs a partir de um botão (pushbutton). O foco principal é garantir que a sequência de acionamento dos LEDs ocorra de forma controlada e sincronizada, respeitando o intervalo de tempo configurado.

---

## Funcionalidades

1. **Acionamento de LEDs com Pushbutton:**
   - Ao pressionar o botão, **todos os três LEDs** (azul, vermelho e verde) serão ligados simultaneamente.

2. **Sequência de Desligamento com Temporizador:**
   - Após o acionamento inicial, o temporizador dispara uma rotina de atraso de **3 segundos (3.000 ms)** para mudar o estado dos LEDs:
     - Primeiro, dois LEDs permanecem ligados.
     - Depois, apenas um LED permanece ligado.

3. **Controle de Estado do Botão:**
   - O botão **não pode iniciar uma nova sequência** enquanto o último LED ainda estiver ligado, garantindo que o sistema finalize o ciclo atual antes de aceitar um novo comando.

4. **Debouncing Opcional:**
   - Implementação opcional de uma rotina de **software debounce** para atenuar o efeito de bouncing do botão.

---

## Tecnologias e Ferramentas Utilizadas

- **Hardware:**
  - **Raspberry Pi Pico W**
  - 03 LEDs (azul, vermelho e verde)
  - 03 Resistores de 330 Ω
  - 01 Botão (Pushbutton)

- **Software:**
  - Linguagem de Programação: **C**
  - Ambiente de Desenvolvimento: **Visual Studio Code**
  - **Pico SDK** para controle de hardware
  - Simulador **Wokwi** integrado ao VS Code

---


## Como Executar o Projeto

1. **Configuração do Ambiente:**
   - Certifique-se de ter o **Visual Studio Code** instalado e configurado para desenvolvimento em C.
   - Instale e configure o **Pico SDK** para trabalhar com o Raspberry Pi Pico W.
   - Conecte o **Raspberry Pi Pico W** ao seu computador e configure-o para ser reconhecido pelo ambiente de desenvolvimento.

2. **Clonar o Repositório:**

```bash
   git clone https://github.com/Ltiicia/Temporizador_OneShot.git
   cd Temporizador_OneShot
```

3. **Compilação e Upload:**
   - Compile o código usando o CMake configurado para o Pico SDK.
   - Faça o upload do código para o Raspberry Pi Pico W.

4. **Execução:**
   - Pressione o botão para iniciar a sequência de acionamento dos LEDs.
   - Observe a transição de estados dos LEDs conforme o temporizador de um disparo é acionado.

---

## Observações Finais

- O código foi desenvolvido para ser facilmente testado tanto em hardware real quanto no simulador Wokwi.
- O sistema garante que o botão só pode ser acionado novamente após o ciclo completo de temporização.
- O uso da ferramenta **BitDogLab** é recomendado para experimentação adicional com LEDs RGB (GPIOs 11, 12 e 13) e o Botão A (GPIO 05).

