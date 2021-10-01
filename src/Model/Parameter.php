<?php


namespace Nerd4ever\KayaModel\Model;


class Parameter
{
    /**
     * @var string
     */
    private $field;
    /**
     * @var ?string
     */
    private $value;

    /**
     * @return string
     */
    public function getField(): string
    {
        return $this->field;
    }

    /**
     * @param string $field
     * @return Parameter
     */
    public function setField(string $field): Parameter
    {
        $this->field = $field;
        return $this;
    }

    /**
     * @return string|null
     */
    public function getValue(): ?string
    {
        return $this->value;
    }

    /**
     * @param string|null $value
     * @return Parameter
     */
    public function setValue(?string $value): Parameter
    {
        $this->value = $value;
        return $this;
    }

    public static function create(string $field, ?string $value)
    {
        return (new Parameter())
            ->setField($field)
            ->setValue($value);
    }
}