SFML_DLL	:= -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE		:=	./src/*.cpp

FILENAME	:= game
BUILD_DIR	:= ./bin

MSG_START	:= "Starting Build"
MSG_END		:= "Finsihed Build"

build:
	@echo ${MSG_START}

	rm -rf ${BUILD_DIR} || true

	mkdir ${BUILD_DIR}

	g++ -o ${BUILD_DIR}/${FILENAME} ${INCLUDE} -I. -I./include ${SFML_DLL}
	@echo ${MSG_END}

	${BUILD_DIR}/${FILENAME}
	