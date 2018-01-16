<?
/**
 * Created by PhpStorm.
 * User: mitryl
 */


class Room
{
    function __construct($Player1)
    {
        $this->Player1 = $Player1;
        $this->CurrentPlayer = $Player1;
    }

    public function AddPlayer2($Player2)
    {
        $this->Player2 = $Player2;
    }

    public $Player1;
    public $Player2;
    public $CurrentPlayer;

    public function SetShip($key, $PlayerName)
    {
        if ($PlayerName == $this->Player1->Name)
            $this->Player1->SetShip($key);
        else
            if ($PlayerName == $this->Player2->Name)
                $this->Player2->SetShip($key);
    }

    public function GetPlayer($PlayerName)
    {
        if ($PlayerName == $this->Player1->Name)
            return $this->Player1;
        else
            if ($PlayerName == $this->Player2->Name)
                return $this->Player2;
    }

    function OtherPlayer($PlayerName)
    {
        if ($PlayerName == $this->Player1->Name)
            return $this->Player2;
        else
            if ($PlayerName == $this->Player2->Name)
                return $this->Player1;
    }

    public function Fire($Name, $Cell)
    {
        $Pl = $this->OtherPlayer($Name);
        $Pl->Board[$Cell][1] = 1;
        if ($Pl->Board[$Cell][0] == 0)
            $this->CurrentPlayer = $Pl;
    }

    public function PrintEnemeBoard($Name)
    {
        $PL = $this->OtherPlayer($Name);
        $Value = "";
        $Value = $Value . "<table>";
        for ($i = 0; $i < 10; $i++) {
            $Value = $Value . "<tr>";
            for ($j = 0; $j < 10; $j++) {
                $key = $j . $i;
                if ($PL->Board[$key] == [0, 0])
                    $Value = $Value . '<td onclick = Fire("' . "$key" . '")> </td>';
                else
                    if ($PL->Board[$key] == [1, 0])
                        $Value = $Value . '<td onclick = Fire("' . "$key" . '")> </td>';
                    else
                        if ($PL->Board[$key] == [0, 1])
                            $Value = $Value . '<td class = missed> </td>';
                        else
                            if ($PL->Board[$key] == [1, 1])
                                $Value = $Value . '<td class = killed> </td>';
            }
            $Value = $Value . "</tr>";
        }
        $Value = $Value . "</table>";
        return $Value;
    }

    public function CheckWin()
    {
        $Player1Alive = false;

        for ($i = 0; $i <= 9; $i++) {
            for ($j = 0; $j <= 9; $j++) {
                if ($this->Player1->Board[$i . $j][0] == 1 && $this->Player1->Board[$i . $j][1] == 0) {
                    $Player1Alive = true;
                    break; //Если есть хотя бы одна палуба по которой не стреляли
                }
            }
        }
        if ($Player1Alive) {
            for ($i = 0; $i <= 9; $i++) {
                for ($j = 0; $j <= 9; $j++) {
                    if ($this->Player2->Board[$i . $j][0] == 1 && $this->Player2->Board[$i . $j][1] == 0) {
                        return null;
                    }
                }
            }
            return $this->Player1;
        } else {
            return $this->Player2;
        }
    }
}

?>