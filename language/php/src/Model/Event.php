<?php


namespace Nerd4ever\KayaModel\Model;

use JsonSerializable;

class Event implements JsonSerializable
{
    /**
     * @var string
     */
    private $name;
    /**
     * @var ?string
     */
    private $identifier;
    /**
     *
     * @var array
     */
    private $parameters;

    /**
     * Event constructor.
     */
    public function __construct()
    {
        $this->parameters = [];
    }

    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @param string $name
     * @return Event
     */
    public function setName(string $name): Event
    {
        $this->name = $name;
        return $this;
    }

    /**
     * @return string|null
     */
    public function getIdentifier(): ?string
    {
        return $this->identifier;
    }

    /**
     * @param string|null $identifier
     * @return Event
     */
    public function setIdentifier(?string $identifier): Event
    {
        $this->identifier = $identifier;
        return $this;
    }

    public function getParameter(string $field): ?Parameter
    {
        foreach ($this->parameters as $p) {
            if (!$p instanceof Parameter) continue;
            if ($field == $p->getField()) return $p;
        }
        return null;
    }

    public function hasParameter(string $field): bool
    {
        return $this->getParameter($field) instanceof Parameter;
    }

    public function addParameter(Parameter $parameter): bool
    {
        if ($this->hasParameter($parameter->getField())) return false;
        $this->parameters[] = $parameter;
        return true;
    }

    /**
     * @return Parameter[]
     */
    public function getParameters(): array
    {
        return $this->parameters;
    }

    /**
     * @param Parameter[] $parameters
     * @return Event
     */
    public function setParameters(array $parameters): Event
    {
        $this->parameters = $parameters;
        return $this;
    }

    public function jsonSerialize(): array
    {
        return [
            'name' => $this->getName(),
            'identifier' => $this->getIdentifier(),
            'parameters' => $this->getParameters()
        ];
    }
}