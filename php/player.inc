<?php
/**
 * Created by PhpStorm.
 * User: mitryl
 */

class Player
{
    function __construct($Name)
    {
        $this->Name = $Name;
        $this->Board = GenerateField();
    }

    public $Name = "";
    public $Board = [];
    public $Ready = false;

    public function SetShip($Key)
    {
        $NewBoard = $this->Board;
        $NewBoard[$Key] = [1, 0];

        if (check_arrangement($NewBoard)) {
            $this->Board[$Key] = [1, 0];
        }
    }

    public function PrintMyBoard()
    {
        $Value = "";
        $Value = $Value . "<table>";
        for ($i = 0; $i < 10; $i++) {
            $Value = $Value . "<tr>";
            for ($j = 0; $j < 10; $j++) {
                $key = $j . $i;
                if ($this->Board[$key] == [0, 0])
                    $Value = $Value . '<td onclick = SetShip("' . "$key" . '")> </td>';
                else
                    if ($this->Board[$key] == [1, 0])
                        $Value = $Value . '<td class = ship></td>';
                    else
                        if ($this->Board[$key] == [0, 1])
                            $Value = $Value . '<td class = missed> </td>';
                        else
                            if ($this->Board[$key] == [1, 1])
                                $Value = $Value . '<td class = killed> </td>';
            }
            $Value = $Value . "</tr>";
        }
        $Value = $Value . "</table>";
        return $Value;
    }

}

?>