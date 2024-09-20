#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
  initVM();
  Chunk chunk;
  initChunk(&chunk);
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 22);
  writeChunk(&chunk, constant, 22);

  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 22);
  writeChunk(&chunk, constant, 22);

  writeChunk(&chunk, OP_ADD, 22);
  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 22);
  writeChunk(&chunk, constant, 22);

  writeChunk(&chunk, OP_DIVIDE, 22);

  writeChunk(&chunk, OP_RETURN, 22);
  disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);
  return 0;
}
