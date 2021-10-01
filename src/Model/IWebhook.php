<?php


namespace src\Nerd4ever\KayaModel\Model;


interface IWebhook
{
    public function getTriggerEvent(): ?Event;
}