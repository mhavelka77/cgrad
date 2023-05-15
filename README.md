# cgrad 

Cgrad is an autograd engine based on karpathy/micrograd. Its purpose is to wrap basic mathematic operations like addition, multiplication and even some nonlinearities like ReLU into a `Value` object that is able to hold the operations and construct a computation tree. This enables for easy computation of all of the partial dervatives (gradients) with respect to all of the Values making up the final expression.

## Run


```bash
g++ -std=c++17 engine.cpp engine.hpp main.cpp && ./a.out
```


## License

[MIT](https://choosealicense.com/licenses/mit/)