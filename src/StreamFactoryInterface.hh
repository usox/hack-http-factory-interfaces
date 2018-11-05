<?hh // strict

namespace Usox\HackHttpFactory;

use namespace Facebook\Experimental\Http\Message;

interface StreamFactoryInterface {
	/**
	 * Create a new stream from a string.
	 *
	 * The stream SHOULD be created with a temporary resource.
	 *
	 * @param string $content String content with which to populate the stream.
	 *
	 * @return Message\StreamInterface
	 */
	public function createStream(string $content = ''): Message\StreamInterface;

	/**
	 * Create a stream from an existing file.
	 *
	 * The file MUST be opened using the given mode, which may be any mode
	 * supported by the `fopen` function.
	 *
	 * The `$filename` MAY be any string supported by `fopen()`.
	 *
	 * @param string $filename Filename or stream URI to use as basis of stream.
	 * @param string $mode Mode with which to open the underlying filename/stream.
	 *
	 * @return Message\StreamInterface
	 */
	public function createStreamFromFile(
		string $filename,
		string $mode = 'r',
	): Message\StreamInterface;

	/**
	 * Create a new stream from an existing resource.
	 *
	 * The stream MUST be readable and may be writable.
	 *
	 * @param resource $resource PHP resource to use as basis of stream.
	 *
	 * @return Message\StreamInterface
	 */
	public function createStreamFromResource(resource $resource): Message\StreamInterface;
}
