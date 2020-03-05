#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <valarray>

#include "pattern.hpp"

Pattern::Pattern(const size_t dim, const int class_label):_v(dim)
{
    _class_label = class_label;
}

Pattern::Pattern(const float values[], const size_t dim, const int class_label):_v(values,dim)
{
    assert(dim>0);
    _class_label = class_label;
}

Pattern::Pattern(const Pattern& other)
{
    this -> _v = other._v;
    this -> _class_label = other._class_label;
}

Pattern::~Pattern()
{}

size_t Pattern::dim() const
{
    return _v.size();
}

int Pattern::class_label() const
{
    return _class_label;
}

float Pattern::operator [](const size_t idx) const
{
    assert((0 <= idx) && (idx < dim()));
    return _v[idx];
}

float Pattern::sum() const
{
    return _v.sum();
}

float Pattern::max() const
{
    return _v.max();
}

float Pattern::min() const
{
    return _v.min();
}

void Pattern::set_class_label(const int new_label)
{
    _class_label = new_label;
}

void Pattern::set_dim(size_t new_dim)
{
    _v.resize(new_dim);
    std::valarray <float> v(_v);
    int tamano;
    if (v.size() < new_dim){
        tamano = v.size();
    }
    else{
        tamano = v.size();
    }

    for (int i = 0; i < tamano; i++){
        _v[i] = v[i];
    }
}

void Pattern::set_value(const size_t i, const float new_v)
{
    assert(0<=i && i<dim());
    _v[i] = new_v;
}

void Pattern::set_values(const float values[])
{
    for (int i = 0; i < this -> dim(); i++){
        _v[i] = values[i];
    }
}

Pattern& Pattern::operator += (const Pattern& o)
{
    assert(o.dim()==dim());
    this -> _v += o._v;
    return *this;
}

Pattern& Pattern::operator -= (const Pattern& o)
{
    assert(o.dim()==dim());
    this -> _v -= o._v;
    return *this;
}

Pattern& Pattern::operator *= (const Pattern& o)
{
    assert(o.dim()==dim());
    this -> _v *= o._v;
    return *this;
}

Pattern& Pattern::operator *= (const float c)
{
    this -> _v *= c;
    return *this;
}

float
distance(const Pattern& a, const Pattern& b)
{
    return sqrt(dot(b - a, b - a));
}


std::ostream& operator << (std::ostream& output, const Pattern& p)
{
    output << p.class_label();
    for (size_t i=0; i<p.dim(); ++i)
        output << ' ' << p[i];
    output << std::endl;
    return output;
}

std::istream& operator >> (std::istream& input, Pattern& p)
    noexcept(false)
{
   std::string line;
   std::getline(input, line);
   if (input && line.size()>0)
   {
       std::istringstream _input;
       _input.str(line);
       int class_label;
       std::vector<float> values;
       _input >> class_label;
       while(_input)
       {
          float v;
          _input >> v;
          if (_input)
              values.push_back(v);
       }
       p.set_dim(values.size());
       p.set_class_label(class_label);
       p.set_values(&values[0]);      
   }
   return input;
}


std::istream&
load_dataset(std::istream& input,
             std::vector<Pattern>& dts) noexcept(false)
{
    if (input)
    {
        size_t size;
        size_t dim;
        input >> size >> dim;
        if (!input)
            throw (std::runtime_error("Error: wrong input format."));
        input.ignore(); //Skips newline.
        dts.resize(size, Pattern(dim));
        for (size_t i = 0; i<size; ++i)
        {
            input >> dts[i];
            if (!input)
                throw (std::runtime_error("Error: wrong input format."));
        }
    }
    return input;
}
