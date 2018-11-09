<?hh // strict

namespace Usox\HackHttpFactory;

use namespace Facebook\Experimental\Http\Message;
use const UPLOAD_ERR_OK;

interface UploadedFileFactoryInterface {
	/**
	 * Create a new uploaded file.
	 *
	 * If a size is not provided it will be determined by checking the size of
	 * the file.
	 *
	 * @see http://php.net/manual/features.file-upload.post-method.php
	 * @see http://php.net/manual/features.file-upload.errors.php
	 *
	 * @param Message\StreamInterface $stream Underlying stream representing the
	 *     uploaded file content.
	 * @param int $size in bytes
	 * @param ?Message\UploadedFileError $error PHP file upload error, if any
	 * @param string $client_filename Filename as provided by the client, if any.
	 * @param string $client_media_type Media type as provided by the client, if any.
	 *
	 * @return Message\UploadedFileInterface
	 *
	 * @throws \InvalidArgumentException If the file resource is not readable.
	 */
	public function createUploadedFile(
		Message\StreamInterface $stream,
		int $size = 0,
		?Message\UploadedFileError $error = null,
		string $client_filename = '',
		string $client_media_type = '',
	): Message\UploadedFileInterface;
}
