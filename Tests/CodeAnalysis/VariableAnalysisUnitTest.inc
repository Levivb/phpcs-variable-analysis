<?php

function function_without_param() {
    echo $var;
    echo "xxx $var xxx";
    echo "xxx {$var} xxx";
    echo "xxx $var $var2 xxx";
    echo "xxx {$var} {$var2} xxx";
    func($var);
    func(12, $var);
    func($var, 12);
    func(12, $var, 12);
    $var = 'set the var';
    echo $var;
    echo "xxx $var xxx";
    echo "xxx {$var} xxx";
    echo "xxx $var $var2 xxx";
    echo "xxx {$var} {$var2} xxx";
    func($var);
    func(12, $var);
    func($var, 12);
    func(12, $var, 12);
    return $var;
}

function function_with_param($param) {
    echo $param;
    echo "xxx $param xxx";
    echo "xxx {$param} xxx";
    $param = 'set the param';
    echo $param;
    echo "xxx $param xxx";
    echo "xxx {$param} xxx";
    return $param;
}

function function_with_default_defined_param($junk, $param = 12) {
    echo $param;
    echo "xxx $param xxx";
    echo "xxx {$param} xxx";
    $param = 'set the param';
    echo $param;
    echo "xxx $param xxx";
    echo "xxx {$param} xxx";
    return $param;
}

function function_with_default_undefined_param($junk, $param = null) {
    echo $param;
    echo "xxx $param xxx";
    echo "xxx {$param} xxx";
    $param = 'set the param';
    echo $param;
    echo "xxx $param xxx";
    echo "xxx {$param} xxx";
    return $param;
}

function function_with_global_var() {
    global $var, $var2;

    echo $var;
    echo $var3;
    return $var2;
}

function function_with_undefined_foreach() {
    foreach ($array as $element1) {
        echo $element1;
    }
    foreach ($array as &$element2) {
        echo $element2;
    }
    foreach ($array as $key1 => $value1) {
        echo "$key1 => $value1\n";
    }
    foreach ($array as $key2 => &$value2) {
        echo "$key2 => $value2\n";
    }
}

function function_with_defined_foreach() {
    $array = array();
    foreach ($array as $element1) {
        echo $element1;
    }
    foreach ($array as &$element2) {
        echo $element2;
    }
    foreach ($array as $key1 => $value1) {
        echo "$key1 => $value1\n";
    }
    foreach ($array as $key2 => &$value2) {
        echo "$key2 => $value2\n";
    }
}

class ClassWithoutMembers {
    function method_without_param() {
        echo $var;
        echo "xxx $var xxx";
        echo "xxx {$var} xxx";
        echo "xxx $var $var2 xxx";
        echo "xxx {$var} {$var2} xxx";
        func($var);
        func(12, $var);
        func($var, 12);
        func(12, $var, 12);
        $var = 'set the var';
        echo $var;
        echo "xxx $var xxx";
        echo "xxx {$var} xxx";
        echo "xxx $var $var2 xxx";
        echo "xxx {$var} {$var2} xxx";
        func($var);
        func(12, $var);
        func($var, 12);
        func(12, $var, 12);
        $this->method_with_member_var();
        return $var;
    }

    function method_with_param($param) {
        echo $param;
        echo "xxx $param xxx";
        echo "xxx {$param} xxx";
        $param = 'set the param';
        echo $param;
        echo "xxx $param xxx";
        echo "xxx {$param} xxx";
        $this->method_with_member_var();
        return $param;
    }

    function method_with_member_var() {
        echo $this->member_var;
    }
}

class ClassWithMembers {
    public $member_var;

    function method_with_member_var() {
        echo $this->member_var;
        echo $this->no_such_member_var;
    }
}

function function_with_this_outside_class() {
    return $this->whatever();
}

function function_with_closure($outer_param) {
    $outer_var  = 1;
    $outer_var2 = 2;
    array_map(function ($inner_param) {
            $inner_var = 1;
            echo $outer_param;
            echo $inner_param;
            echo $outer_var;
            echo $outer_var2;
            echo $inner_var;
        }, array());
    array_map(function () use ($outer_var, $outer_var3, &$outer_param) {
            $inner_var2 = 2;
            echo $outer_param;
            echo $inner_param;
            echo $outer_var;
            echo $outer_var2;
            echo $outer_var3;
            echo $inner_var;
            echo $inner_var2;
        }, array());
    echo $outer_var;
    echo $outer_var2;
    echo $outer_var3;
    echo $inner_param;
    echo $inner_var;
    echo $inner_var2;
}

function &function_with_return_by_reference_and_param($param) {
    echo $param;
    return $param;
}

function function_with_static_var() {
    static $static1, $static_num = 12, $static_neg_num = -1.5, $static_string = 'abc', $static_string2 = "def", $static_define = MYDEFINE, $static_constant = MyClass::CONSTANT, $static2;
    echo $static1;
    echo $static_num;
    echo $static2;
    echo $var;
}

function function_with_pass_by_reference_param(&$param) {
    echo $param;
}

function function_with_pass_by_reference_calls() {
    echo $matches;
    echo $needle;
    echo $haystack;
    preg_match('/(abc)/', 'defabcghi', $matches);
    preg_match($needle,   'defabcghi', $matches);
    preg_match('/(abc)/', $haystack,   $matches);
    echo $matches;
    echo $needle;
    echo $haystack;
}

function function_with_try_catch() {
    echo $e;
    $var = 1;
    echo $var;
    try {
        echo $e;
        echo $var;
    } catch (Exception $e) {
        echo $e;
        echo $var;
    }
    echo $e;
    echo $var;
}

class ClassWithThisInsideClosure {
    function method_with_this_inside_closure() {
        echo $this;
        echo "$this";
        array_map(function ($inner_param) {
                echo $this;
                echo "$this";
            }, array());
        echo $this;
        echo "$this";
    }
}

function function_with_inline_assigns() {
    echo $var;
    ($var = 12) && $var;
    echo $var;
    echo $var2;
    while ($var2 = whatever()) {
        echo $var2;
    }
    echo $var2;
}