build:
	g++ -std=c++17 .tests/"$(name)".cpp -o "$(name)".out

build_sanitized:
	g++ -std=c++17 .tests/"$(name)".cpp -o "$(name)".out -fsanitize=address

test_with_linter:
	cpplint --filter=-legal/copyright solutions/"$(name)".h \
 	&& ./"$(name)".out -d yes "[task:$(name)]"

test:
	./"$(name)".out -d yes "[task:$(name)]"

clear:
	rm [a-z][0-9].out
