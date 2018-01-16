var timerId;

function StartGame() {
    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {Enter: ""},
        success: function (data) {
            $("#MyField").html(data);
        }
    });
}

function SetShip(Cell) {
    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {Set: Cell},
        success: function (data) {
            $("#MyField").html(data);
        }
    });
}

function Fire(Cell) {
    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {Fire: Cell},
        success: function (data) {
            $("#TargetField").html(data);
        }
    });

}

function StartBattle() {
    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {Start: ""},
        success: function (data) {
            $("#TargetField").html(data);

            const message1 = "Разместите корабли правильно";
            const message2 = "Противник не найден";
            if (data !== message1 && data !== message2) {
                timerId = setInterval(GetState, 2000);
                $("#Button").remove();
                $("#EnemyName").html("Корабли противника");
            }
        }
    });

}

function GetState() {
    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {MyField: ""},
        success: function (data) {
            $("#MyField").html(data);
        }
    });

    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {CurrentPlayer: ""},
        success: function (data) {
            $("#CurrentPlayer").html(data);
        }
    });

    $.ajax({
        type: "POST",
        url: "../php/main.php",
        data: {Win: ""},
        success: function (data) {
            if (data !== "") {
                alert(data);
                clearInterval(timerId);
            }
        }
    });
}