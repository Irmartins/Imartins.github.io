<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Calculadora de Projetos</title>
  <style>
    body {
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      background-color: #f8f9fa;
      margin: 0;
      padding: 1rem;
      display: flex;
      flex-direction: column;
      align-items: center;
      color: #333;
    }

    h2 {
      margin-bottom: 1.5rem;
      font-weight: 500;
      font-size: 1.3rem;
    }

    .grid {
      display: flex;
      flex-wrap: wrap;
      gap: 1rem;
      justify-content: center;
      max-width: 900px;
    }

    .main-cards {
      display: flex;
      flex-wrap: wrap;
      gap: 1rem;
      justify-content: center;
      width: 100%;
      margin-bottom: 1rem;
    }

    .secondary-cards {
      display: flex;
      flex-wrap: wrap;
      gap: 1rem;
      justify-content: center;
      width: 100%;
    }

    .card {
      background: white;
      padding: 1rem;
      border-radius: 0.8rem;
      box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);
      position: relative;
      flex: 1;
      min-width: 200px;
    }

    .card-small {
      min-width: 150px;
      max-width: 180px;
    }

    .titulo {
      font-weight: 600;
      margin-bottom: 0.5rem;
      font-size: 0.95rem;
    }

    .info {
      font-size: 0.7rem;
      color: #777;
      margin-bottom: 0.8rem;
    }

    .input-group {
      margin-bottom: 0.8rem;
    }

    .input-label {
      display: block;
      font-size: 0.7rem;
      color: #777;
      margin-bottom: 0.2rem;
    }

    input {
      width: 100%;
      padding: 0.5rem;
      border-radius: 6px;
      border: 1px solid #ccc;
      font-size: 0.9rem;
      box-sizing: border-box;
    }

    .input-row {
      display: flex;
      gap: 0.5rem;
    }

    .input-row .input-group {
      flex: 1;
      margin-bottom: 0.5rem;
    }

    .valor-input {
      position: relative;
    }
    
    .valor-input input {
      padding-left: 2rem;
    }
    
    .valor-input::before {
      content: "R$";
      position: absolute;
      left: 0.6rem;
      top: 0.5rem;
      color: #333;
      z-index: 1;
      font-weight: bold;
      font-size: 0.9rem;
    }

    .resultado {
      font-size: 0.8rem;
      margin-top: 0.2rem;
      font-weight: 500;
      white-space: pre-line;
      line-height: 1.3;
    }

    button {
      margin-top: 0.8rem;
      padding: 5px 12px;
      background-color: #ddd;
      border: none;
      border-radius: 5px;
      cursor: pointer;
      font-size: 0.8rem;
    }

    button:hover {
      background-color: #ccc;
    }

    .clear-all {
      position: absolute;
      top: 8px;
      left: 8px;
      background-color: #d9534f;
      color: white;
      padding: 5px 10px;
      border: none;
      border-radius: 5px;
      cursor: pointer;
      font-size: 0.8rem;
    }

    @media (max-width: 600px) {
      .card {
        min-width: 100%;
      }
      
      .input-row {
        flex-direction: column;
        gap: 0;
      }
    }
  </style>
</head>
<body>
  <button class="clear-all" onclick="limparTodos()">Limpar tudo</button>

  <h2>Calculadora de Projetos</h2>

  <div class="grid">
    <div class="main-cards">
      <!-- Visitas por Hora -->
      <div class="card card-small">
        <div class="titulo">Distribuição de Visitas</div>
        <div class="info">Informe a quantidade de visitas</div>
        
        <div class="input-row">
          <div class="input-group">
            <label class="input-label">1h</label>
            <input type="number" id="visita1" oninput="calcularDistribuicao()">
          </div>
          
          <div class="input-group">
            <label class="input-label">2h</label>
            <input type="number" id="visita2" oninput="calcularDistribuicao()">
          </div>
        </div>
        
        <div class="input-row">
          <div class="input-group">
            <label class="input-label">3h</label>
            <input type="number" id="visita3" oninput="calcularDistribuicao()">
          </div>
          
          <div class="input-group">
            <label class="input-label">4h</label>
            <input type="number" id="visita4" oninput="calcularDistribuicao()">
          </div>
        </div>
        
        <div class="resultado" id="resDistribuicao"></div>
        <button onclick="limparDistribuicao()">Limpar</button>
      </div>

      <!-- Valor por Hora -->
      <div class="card card-small">
        <div class="titulo">Valor por Hora</div>
        <div class="info">Demais Cadeias: R$ 105,00<br>Inclusão Produtiva: R$ 74,00<br>Agroindústria: R$ 142,00<br>Consultor Master: R$ 186,00</div>
        <div class="input-group">
          <label class="input-label">Horas</label>
          <input type="number" id="horas" oninput="calcularHoras()">
        </div>
        <div class="resultado" id="horaDemais"></div>
        <div class="resultado" id="horaInclusao"></div>
        <div class="resultado" id="horaAgro"></div>
        <div class="resultado" id="horaMaster"></div>
        <button onclick="limparHoras()">Limpar</button>
      </div>

      <!-- Campo Dinâmico -->
      <div class="card card-small">
        <div class="titulo">Campo Dinâmico</div>
        <div class="input-group">
          <label class="input-label">% Próprio</label>
          <input type="number" id="percProprio" oninput="calcularDinamico()">
        </div>
        <div class="input-group">
          <label class="input-label">% Terceiro</label>
          <input type="number" id="percTerceiro" oninput="calcularDinamico()">
        </div>
        <div class="input-group">
          <label class="input-label">Valor total</label>
          <div class="valor-input">
            <input type="text" id="valorDinamico" oninput="formatarNumero(this); calcularDinamico()">
          </div>
        </div>
        <div class="resultado" id="resDinamico"></div>
        <button onclick="limparDinamico()">Limpar</button>
      </div>
    </div>

    <div class="secondary-cards">
      <!-- Mais ATeG -->
      <div class="card card-small">
        <div class="titulo">Mais ATeG</div>
        <div class="info">77% Próprio<br>23% Terceiro</div>
        <div class="input-group">
          <label class="input-label">Valor total</label>
          <div class="valor-input">
            <input type="text" id="maisAteg" oninput="formatarNumero(this); calcularProjeto('maisAteg', 77, 23)">
          </div>
        </div>
        <div class="resultado" id="resMaisAteg"></div>
        <button onclick="limparCampo('maisAteg', 'resMaisAteg')">Limpar</button>
      </div>

      <!-- Incentivo Expansão -->
      <div class="card card-small">
        <div class="titulo">Incentivo Expansão</div>
        <div class="info">72,80% Próprio<br>27,20% Terceiro</div>
        <div class="input-group">
          <label class="input-label">Valor total</label>
          <div class="valor-input">
            <input type="text" id="incentivo" oninput="formatarNumero(this); calcularProjeto('incentivo', 72.8, 27.2)">
          </div>
        </div>
        <div class="resultado" id="resIncentivo"></div>
        <button onclick="limparCampo('incentivo', 'resIncentivo')">Limpar</button>
      </div>

      <!-- Agronordeste II -->
      <div class="card card-small">
        <div class="titulo">Agronordeste II</div>
        <div class="info">75,64% Próprio<br>24,36% Terceiro</div>
        <div class="input-group">
          <label class="input-label">Valor total</label>
          <div class="valor-input">
            <input type="text" id="agro" oninput="formatarNumero(this); calcularProjeto('agro', 75.64, 24.36)">
          </div>
        </div>
        <div class="resultado" id="resAgro"></div>
        <button onclick="limparCampo('agro', 'resAgro')">Limpar</button>
      </div>

      <!-- Parceria 1 -->
      <div class="card card-small">
        <div class="titulo">Parceria 1</div>
        <div class="info">50% Próprio<br>50% Terceiro</div>
        <div class="input-group">
          <label class="input-label">Valor total</label>
          <div class="valor-input">
            <input type="text" id="parceria" oninput="formatarNumero(this); calcularProjeto('parceria', 50, 50)">
          </div>
        </div>
        <div class="resultado" id="resParceria"></div>
        <button onclick="limparCampo('parceria', 'resParceria')">Limpar</button>
      </div>
    </div>
  </div>

  <script>
    function formatReal(valor) {
      // Formata com separador de milhar e decimal
      return 'R$ ' + valor.toLocaleString('pt-BR', { minimumFractionDigits: 2, maximumFractionDigits: 2 });
    }

    function formatResultado(valor) {
      // Formata apenas com decimal (sem separador de milhar)
      return valor.toFixed(2).replace('.', ',');
    }

    function desformatarNumero(valor) {
      if (typeof valor !== 'string') return valor;
      // Remove tudo que não é número
      const apenasNumeros = valor.replace(/\D/g, '');
      // Converte para float (considerando os 2 últimos dígitos como centavos)
      return parseFloat(apenasNumeros) / 100;
    }

    function formatarNumero(input) {
      // Obtém posição do cursor
      const cursorPos = input.selectionStart;
      const valorAtual = input.value;
      
      // Remove todos os caracteres não numéricos
      const apenasNumeros = valorAtual.replace(/\D/g, '');
      
      if (apenasNumeros === '') {
        input.value = '';
        return;
      }
      
      // Converte para número (últimos 2 dígitos são centavos)
      const numero = parseFloat(apenasNumeros) / 100;
      
      // Formata com separadores
      input.value = numero.toLocaleString('pt-BR', {
        minimumFractionDigits: 2,
        maximumFractionDigits: 2
      });
      
      // Ajusta posição do cursor
      const novoCursorPos = cursorPos + (input.value.length - valorAtual.length);
      input.setSelectionRange(novoCursorPos, novoCursorPos);
      
      // Chama função de cálculo
      const id = input.id;
      if (id === 'valorDinamico') calcularDinamico();
      else if (['parceria', 'maisAteg', 'incentivo', 'agro'].includes(id)) {
        const percentages = {
          parceria: [50, 50],
          maisAteg: [77, 23],
          incentivo: [72.8, 27.2],
          agro: [75.64, 24.36]
        };
        calcularProjeto(id, ...percentages[id]);
      }
    }

    function calcularDistribuicao() {
      let totalVisitas = 0;
      let totalHoras = 0;
      for (let i = 1; i <= 4; i++) {
        const visitas = parseInt(document.getElementById('visita' + i).value) || 0;
        totalVisitas += visitas;
        totalHoras += visitas * i;
      }
      document.getElementById('resDistribuicao').innerText = `Total: ${totalVisitas} visitas\n${totalHoras} horas`;
    }

    function limparDistribuicao() {
      for (let i = 1; i <= 4; i++) document.getElementById('visita' + i).value = '';
      document.getElementById('resDistribuicao').innerText = '';
    }

    function calcularHoras() {
      const horas = parseFloat(document.getElementById('horas').value) || 0;
      document.getElementById('horaDemais').innerText = `Demais Cadeias: ${(horas * 105).toFixed(2).replace('.', ',')}`;
      document.getElementById('horaInclusao').innerText = `Inclusão Produtiva: ${(horas * 74).toFixed(2).replace('.', ',')}`;
      document.getElementById('horaAgro').innerText = `Agroindústria: ${(horas * 142).toFixed(2).replace('.', ',')}`;
      document.getElementById('horaMaster').innerText = `Consultor Master: ${(horas * 186).toFixed(2).replace('.', ',')}`;
    }

    function limparHoras() {
      document.getElementById('horas').value = '';
      document.getElementById('horaDemais').innerText = '';
      document.getElementById('horaInclusao').innerText = '';
      document.getElementById('horaAgro').innerText = '';
      document.getElementById('horaMaster').innerText = '';
    }

    function calcularProjeto(id, percProprio, percTerceiro) {
      const valor = desformatarNumero(document.getElementById(id).value);
      const resId = 'res' + capitalize(id);
      if (isNaN(valor)) return document.getElementById(resId).innerText = '';
      const proprio = valor * (percProprio / 100);
      const terceiro = valor * (percTerceiro / 100);
      document.getElementById(resId).innerText =
        `Próprio: ${formatResultado(proprio)}\nTerceiro: ${formatResultado(terceiro)}`;
    }

    function calcularDinamico() {
      const valor = desformatarNumero(document.getElementById('valorDinamico').value);
      const percProprio = parseFloat(document.getElementById('percProprio').value);
      const percTerceiro = parseFloat(document.getElementById('percTerceiro').value);
      if (isNaN(valor) || isNaN(percProprio) || isNaN(percTerceiro)) return document.getElementById('resDinamico').innerText = '';
      const proprio = valor * (percProprio / 100);
      const terceiro = valor * (percTerceiro / 100);
      document.getElementById('resDinamico').innerText =
        `Próprio: ${formatResultado(proprio)}\nTerceiro: ${formatResultado(terceiro)}`;
    }

    function limparCampo(inputId, resultId) {
      document.getElementById(inputId).value = '';
      document.getElementById(resultId).innerText = '';
    }

    function limparDinamico() {
      document.getElementById('valorDinamico').value = '';
      document.getElementById('percProprio').value = '';
      document.getElementById('percTerceiro').value = '';
      document.getElementById('resDinamico').innerText = '';
    }

    function limparTodos() {
      document.querySelectorAll('input').forEach(el => el.value = '');
      document.querySelectorAll('.resultado').forEach(el => el.innerText = '');
    }

    function capitalize(str) {
      return str.charAt(0).toUpperCase() + str.slice(1);
    }
  </script>
</body>
</html>
