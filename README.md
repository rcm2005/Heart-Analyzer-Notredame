# ECG-Emulator-Notredame
A Notredame nos desafiou na Global Solutions a tornar a saúde mais acessível à todos através da tecnologia, eu Rafael Mattos e minha dupla Vinicius Yamashita desenvolvemos soluções para os problemas do cenário atual do sistema de saúde.

- RM:99874- Rafael Carvalho mattos
- RM:550908-Vinicius Santos Yamashita de Farias




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

