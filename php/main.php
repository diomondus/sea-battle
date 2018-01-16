<?php
/**
 * Created by PhpStorm.
 * User: mitryl
 */

const FILENAME = 'room.txt';
const COOKIE_NAME = "name";

ini_set('display_errors', 'Off');
error_reporting('E_ALL');

//$Rooms;

include("constants.inc");
include("functions.inc");
include("player.inc");
include("room.inc");

if (isset($_POST['Enter'])) {

    $Room = unserialize(file_get_contents(FILENAME));

    $Pl;

    if (isset($Room->Player1) AND isset($Room->Player2)) {
        file_put_contents(FILENAME, "");
        $Room = unserialize(file_get_contents(FILENAME));

    } else if (!isset($Room->Player1)) {
        $Pl = new Player("1");
        setcookie(COOKIE_NAME, $Pl->Name);
        $Room = new Room($Pl);
        $OutPut = $Pl->PrintMyBoard();
        echo $OutPut;

    } else if (!isset($Room->Player2)) {
        $Pl = new Player("2");
        setcookie(COOKIE_NAME, $Pl->Name);
        $Room->AddPlayer2($Pl);
        $OutPut = $Pl->PrintMyBoard();
        echo $OutPut;
    }

    file_put_contents(FILENAME, serialize($Room));

} else if (isset($_POST['Set'])) {
    $Room = unserialize(file_get_contents(FILENAME));
    $Room->SetShip($_POST['Set'], $_COOKIE[COOKIE_NAME]);

    file_put_contents(FILENAME, serialize($Room));

    $Player = $Room->GetPlayer($_COOKIE[COOKIE_NAME]);
    echo $Player->PrintMyBoard();

} else if (isset($_POST['Start'])) {
    $Room = unserialize(file_get_contents(FILENAME));
    $Pl = $Room->GetPlayer($_COOKIE[COOKIE_NAME]);
    if (null != $Room->OtherPlayer($_COOKIE[COOKIE_NAME]))
        if (IsFinalArrangement($Pl->Board)) {
            $Pl->Ready = true;
            echo $Room->PrintEnemeBoard($_COOKIE[COOKIE_NAME]);
            file_put_contents(FILENAME, serialize($Room));
        } else {
            echo MESSAGE_SET_SHIPS_CORRECTLY;
        }
    else {
        echo MESSAGE_ENEMY_NOT_FOUND;
    }

} else if (isset($_POST['MyField'])) {
    $Room = unserialize(file_get_contents(FILENAME));
    $Pl = $Room->GetPlayer($_COOKIE[COOKIE_NAME]);
    echo $Pl->PrintMyBoard();

} else if (isset($_POST['Fire'])) {
    $Room = unserialize(file_get_contents(FILENAME));
    if ($Room->OtherPlayer($_COOKIE[COOKIE_NAME])->Ready) {
        if ($Room->CurrentPlayer == $Room->GetPlayer($_COOKIE[COOKIE_NAME]))
            $Room->Fire($_COOKIE[COOKIE_NAME], $_POST['Fire']);

        file_put_contents(FILENAME, serialize($Room));
    } else {
        echo MESSAGE_ENEMY_NOT_READY;
    }
    echo $Room->PrintEnemeBoard($_COOKIE[COOKIE_NAME]);

} else if (isset($_POST['CurrentPlayer'])) {
    $Room = unserialize(file_get_contents(FILENAME));
    if ($Room->CurrentPlayer == $Room->GetPlayer($_COOKIE[COOKIE_NAME])) {
        echo MESSAGE_YOUR_TURN;
    } else {
        echo MESSAGE_ENEMY_TURN . "";
    }

} else if (isset($_POST['Win'])) {
    $Room = unserialize(file_get_contents(FILENAME));
    if ($Room->OtherPlayer($_COOKIE[COOKIE_NAME])->Ready) {
        if ($Room->CheckWin() != null) {
            if ($Room->CheckWin() == $Room->GetPlayer($_COOKIE[COOKIE_NAME])) {
                echo MESSAGE_YOU_WIN;
            } else {
                echo MESSAGE_YOU_LOOSE;
            }
        }
    }
}
?>