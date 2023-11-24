# ECG-Emulator-Notredame
A Notredame nos desafiou na Global Solutions a tornar a saúde mais acessível à todos através da tecnologia, eu Rafael Mattos e minha dupla Vinicius Yamashita desenvolvemos soluções para os problemas do cenário atual do sistema de saúde.

- RM:99874- Rafael Carvalho mattos
- RM:550908-Vinicius Santos Yamashita de Farias

Identificação do problema:

Os dados no relatório do Relatório do Ministério da Saúde apontam que a fila do SUS tem mais de 0,5 milhão de pessoas à espera de cirurgias eletivas em 16 estados do Brasil, e é possível perceber que após a pandemia do COVID-19 as filas aumentaram ainda mais. Logo, é possível afirmar que as filas são um problema que sempre existirá em qualquer tipo de serviço, então o objetivo é reduzir ao máximo o tempo de espera otimizando a organização do atendimento.

Nossa solução:
Diante disso, o projeto proposto apresenta uma abordagem inovadora no cenário da saúde, onde a convergência da tecnologia e dos cuidados cardíacos se destaca como uma prioridade. Focando na criação de um Sistema de Triagem Remota com Eletrocardiograma Automatizado, buscamos revolucionar a maneira como os pacientes são avaliados e diagnosticados, dando ênfase na eficiência e na detecção precoce de condições cardíacas. Esta iniciativa promete não apenas reduzir substancialmente o tempo que os pacientes aguardam para receber os cuidados, mas também aprimorar a capacidade dos profissionais de saúde em fornecer cuidados mais personalizados e ágeis. Ao unir a praticidade da triagem remota com a realização automática de ECG, nosso projeto almeja impactar positivamente a prestação de cuidados em geral com ênfase nos cardíacos, promovendo uma abordagem proativa e acessível para a saúde cardiovascular.


O dispositivo ECG:
<br>
![Imagem8](https://github.com/rcm2005/ECG-Emulator-Notredame/assets/68041167/4ac9b933-20db-4ead-bacc-a9923b166279)
<br>

(Figura 5: Sensor eletrocardiograma, display e ESP32)

O dispositivo Heart Analyzer é o que torna a captura dos sinais cardíacos possível, nessa simulação utilizamos 3 potenciômetros para simular os 3 eletrodos do sensor. Os sinais enviados pelo coração são capturados nos eletrodos, processados pelo módulo ESP32 e enviados para a nuvem utilizando o protocolo MQTT, e serão captados posteriormente pelo nosso programa




Junto do dispositivo ECG, também desenvolvemos a aplicação python onde é possível importar os dados do sensor e plotar um gráfico dos dados do eletrocardiograma na tela, como pode ser visto na figura 10. <br>


![Imagem5](https://github.com/rcm2005/ECG-Emulator-Notredame/assets/68041167/aade4a68-1d3e-4c7c-8e3a-019b939b98ab)
<br>
          (Figura 10: Gráfico com dados de exame gerado pelo Health Center)

Dessa forma fornecemos a melhor experiência possível para o paciente ajudando os médicos a oferecer cuidados.

