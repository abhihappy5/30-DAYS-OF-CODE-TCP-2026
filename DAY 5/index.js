const board = document.getElementById('board');
const cells = document.querySelectorAll('.cell');
const messageText = document.getElementById('message-text');
const restartBtn = document.getElementById('restart');

let currentPlayer = 'X';
let boardState = Array(9).fill(null);
let gameActive = true;

const winningCombinations = [
    [0,1,2], [3,4,5], [6,7,8],
    [0,3,6], [1,4,7], [2,5,8],
    [0,4,8], [2,4,6]
];

cells.forEach(cell => {
    cell.addEventListener('click', () => {
        const index = cell.dataset.index;
        if (!boardState[index] && gameActive) {
            boardState[index] = currentPlayer;
            cell.textContent = currentPlayer;
            cell.classList.add(currentPlayer === 'X' ? 'x' : 'o');
            checkResult();
            currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
            if(gameActive) messageText.textContent = `${currentPlayer}'s turn!`;
        }
    });
});

function checkResult() {
    let winner = null;

    winningCombinations.forEach(combo => {
        const [a, b, c] = combo;
        if(boardState[a] && boardState[a] === boardState[b] && boardState[a] === boardState[c]){
            winner = boardState[a];
            combo.forEach(i => cells[i].classList.add('win'));
        }
    });

    if(winner) {
        messageText.textContent = `${winner} Wins!`;
        gameActive = false;
        return;
    }

    if(!boardState.includes(null)) {
        messageText.textContent = `It's a Draw!`;
        cells.forEach(cell => cell.classList.add('draw'));
        gameActive = false;
    }
}

restartBtn.addEventListener('click', () => {
    boardState.fill(null);
    cells.forEach(cell => {
        cell.textContent = '';
        cell.classList.remove('win', 'draw', 'x', 'o');
    });
    currentPlayer = 'X';
    gameActive = true;
    messageText.textContent = `Your turn!`;
});

