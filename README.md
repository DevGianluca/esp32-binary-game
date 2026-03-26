# 🕹️ Jogo do Binário - ESP32

![Circuito do Jogo](Sem%20título.png)

Um jogo interativo focado na conversão mental de caracteres da Tabela ASCII para o formato Binário, desenvolvido inteiramente em **C/C++** nativo para o microcontrolador **ESP32**. 

🔗 **[Clique aqui para jogar e testar a simulação interativa no Wokwi](https://wokwi.com/projects/459591086664680449)**

> **⚠️ AVISO IMPORTANTE SOBRE O INÍCIO:** > Existe uma pequena diferença na forma de iniciar o jogo entre as versões:
> * **No Código Real (.ino):** Para começar, você deve pressionar os **dois botões brancos** simultaneamente.
> * **Na Simulação Wokwi:** Devido a limitações de input simultâneo no navegador, basta pressionar apenas o **botão à direita** para iniciar a partida.

## 🎯 Características do Jogo
* **Desafio Lógico:** O sistema gera uma letra aleatória e o jogador precisa inserir o valor binário correspondente (8 bits) sem usar calculadoras. Como não há limite de tempo, o foco é 100% na precisão!
* **Máquina de Estados:** Arquitetura de código limpa, dividida em fases (Início, Jogo, Fim) para garantir performance e evitar travamentos no hardware.
* **Feedback Sensorial:** Conta com um Buzzer para efeitos sonoros (acertos, erros e *easter eggs*) e LEDs indicadores para acompanhamento das vidas e acertos.

## 🎮 Mecânicas e Controles
O jogo é controlado inteiramente por 4 botões físicos na protoboard. Eis a função de cada um:

* ⚪ **Botão Esquerdo:** Insere o bit **`0`** na sua resposta.
* ⚪ **Botão Direito:** Insere o bit **`1`** na sua resposta.
* 🔴 **Botão Vermelho:** Pressione para **Confirmar e Enviar** a sua resposta final para validação.
* ⚫ **Botão BOOT (Pino 0 da placa):** É o botão de segurança. Se você digitar um bit errado sem querer, pressione este botão para **Apagar a resposta atual** e começar a digitar a letra de novo, sem perder vidas.

## ⚠️ Aviso sobre o Hardware e Configurações
Este código foi projetado e testado para a minha configuração específica de pinagem no ESP32. Se você for clonar este repositório para montar na sua casa, preste muita atenção aos pinos definidos no início do arquivo `.ino`.

**Minhas configurações de pinos atuais:**
* LEDs de Vida (Vermelhos): Pinos `5`, `18` e `19`
* LED de Acerto (Verde): Pino `4`
* Botões de Jogo (0, 1 e Enviar): Pinos `21`, `22` e `23`
* Botão de Apagar: Pino `0` (BOOT)
* Buzzer: Pino `15`

> *Dica: Se você usar outros pinos ou um modelo diferente de placa, não se esqueça de alterar as variáveis `#define` nas primeiras linhas do código!*

## 🚀 Roadmap e Próximos Passos (Da V1 para V2)
Esta é a **Versão 1.0** do projeto, focada na estabilidade da lógica principal e no controle do hardware físico. As próximas atualizações planejadas são:

* **[ ]** Integração com o módulo Wi-Fi do ESP32.
* **[ ]** Criação de uma API de Back-end para receber a pontuação dos jogadores.
* **[ ]** Implementação de um Banco de Dados em nuvem para criar um ranking global (Leaderboard).

---
## 🏆 Boa sorte!
O jogo exige bastante atenção, lógica e os erros custam caro. Você tem apenas 3 vidas. Clone o repositório, monte o circuito, compile o código e **boa sorte para conseguir a maior pontuação possível!**
