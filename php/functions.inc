<?php
/**
 * Created by PhpStorm.
 * User: mitryl
 */

function GenerateField()
{
    $Field = [];

    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            $key = $j . $i;
            $value = [0, 0];
            $Field[$key] = $value;
        }
    }
    return $Field;
}


function check_arrangement($Board)
{

    for ($i = 0; $i <= 9; $i++)
        for ($j = 0; $j <= 9; $j++) {
            $key = $j . $i;
            if ($Board[$key] == [1, 0]) {
                $keys = [];

                $keys[] = ($j + 1) . ($i - 1);
                $keys[] = ($j - 1) . ($i - 1);
                $keys[] = ($j + 1) . ($i + 1);
                $keys[] = ($j - 1) . ($i - 1);

                for ($k = 0; $k < count($keys); $k++) {
                    if ($Board[$keys[$k]] == [1, 0]) {
                        return false;
                    }
                }
            }
        }

    $iSingleDeckCounter = 0;
    $iDoubleDeckCounter = 0;
    $iThreeDeckCounter = 0;
    $iFourDeckCounter = 0;

    for ($i = 0; $i <= 9; $i++)
        for ($k = 0; $k <= 9; $k++) {

            if ($Board[$k . $i][0] == 1) {
                $Board[$k . $i][0] = 2;

                if ($Board[$k . ($i + 1)][0] == 1) {
                    $Board[$k . ($i + 1)][0] = 2;

                    if ($Board[$k . ($i + 2)][0] == 1) {
                        $Board[$k . ($i + 2)][0] = 2;

                        if ($Board[$k . ($i + 3)][0] == 1) {
                            $Board[$k . ($i + 2)][0] = 2;

                            $iFourDeckCounter += 1;

                            if ($Board[$k . ($i + 4)][0] == 1)
                                return false;
                        } else {
                            $iThreeDeckCounter += 1;
                        }
                    } else {
                        $iDoubleDeckCounter += 1;
                    }
                } else if ($Board[($k + 1) . $i][0] == 1) {
                    $Board[($k + 1) . $i][0] = 2;

                    if ($Board[($k + 2) . $i][0] == 1) {
                        $Board[($k + 2) . $i][0] = 2;

                        if ($Board[($k + 3) . $i][0] == 1) {
                            $Board[($k + 3) . $i][0] = 2;

                            $iFourDeckCounter += 1;

                            if ($Board[($k + 4) . $i][0] == 1)
                                return false;

                        } else {
                            $iThreeDeckCounter += 1;
                        }
                    } else {
                        $iDoubleDeckCounter += 1;
                    }
                } else {
                    $iSingleDeckCounter += 1;
                }
            }
        }

    for ($i = 0; $i <= 1; $i++) {
        if ($iFourDeckCounter == $i) {
            for ($i1 = 0; $i1 <= 3 - $i; $i1++) {
                if ($iThreeDeckCounter == $i1) {
                    for ($i2 = 0; $i2 <= 6 - $i1 - $i; $i2++)
                        if ($iDoubleDeckCounter == $i2) {
                            for ($i3 = 0; $i3 <= 10 - $i2 - $i1 - $i; $i3++)
                                if ($iSingleDeckCounter == $i3)
                                    return true;
                        }
                }
            }
        }
    }

    return false;
}

function IsFinalArrangement($Board)
{
    $iSingleDeckCounter = 0;
    $iDoubleDeckCounter = 0;
    $iThreeDeckCounter = 0;
    $iFourDeckCounter = 0;

    for ($i = 0; $i <= 9; $i++)
        for ($k = 0; $k <= 9; $k++) {

            if ($Board[$k . $i][0] == 1) {
                $Board[$k . $i][0] = 2;

                if ($Board[$k . ($i + 1)][0] == 1) {
                    $Board[$k . ($i + 1)][0] = 2;

                    if ($Board[$k . ($i + 2)][0] == 1) {
                        $Board[$k . ($i + 2)][0] = 2;

                        if ($Board[$k . ($i + 3)][0] == 1) {
                            $Board[$k . ($i + 2)][0] = 2;

                            $iFourDeckCounter += 1;

                            if ($Board[$k . ($i + 4)][0] == 1)
                                return false;
                        } else {
                            $iThreeDeckCounter += 1;
                        }
                    } else {
                        $iDoubleDeckCounter += 1;
                    }
                } else if ($Board[($k + 1) . $i][0] == 1) {
                    $Board[($k + 1) . $i][0] = 2;

                    if ($Board[($k + 2) . $i][0] == 1) {
                        $Board[($k + 2) . $i][0] = 2;

                        if ($Board[($k + 3) . $i][0] == 1) {
                            $Board[($k + 3) . $i][0] = 2;

                            $iFourDeckCounter += 1;

                            if ($Board[($k + 4) . $i][0] == 1)
                                return false;

                        } else {
                            $iThreeDeckCounter += 1;
                        }
                    } else {
                        $iDoubleDeckCounter += 1;
                    }
                } else {
                    $iSingleDeckCounter += 1;
                }
            }
        }

    if ($iSingleDeckCounter == 4 && $iDoubleDeckCounter == 3 && $iThreeDeckCounter == 2 && $iFourDeckCounter == 1)
        return true;
    return false;
}

?>